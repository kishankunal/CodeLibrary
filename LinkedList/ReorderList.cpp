//https://www.interviewbit.com/problems/reorder-list/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL, *curr = head, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *reorderList(ListNode *A)
{
    ListNode *slow = A;
    ListNode *fast = A;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *temp = slow->next;
    slow->next = NULL;
    temp = reverse(temp);
    slow = A;
    while (temp && A)
    {
        ListNode *x = A->next;
        ListNode *y = temp->next;
        A->next = temp;
        temp->next = x;
        A = x;
        temp = y;
    }
    return slow;
}
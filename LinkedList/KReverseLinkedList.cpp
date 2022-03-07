//https://www.interviewbit.com/problems/k-reverse-linked-list/
#include <bits/stdc++.h>
using namespace std;

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
ListNode *Solution::reverseList(ListNode *A, int B)
{
    if (!A || B == 1)
    {
        return A;
    }
    ListNode *curr = A;
    for (int i = 0; i < B - 1; i++)
    {
        curr = curr->next;
    }
    ListNode *temp = curr->next;
    curr->next = NULL;
    curr = reverse(A);
    A = curr;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = reverseList(temp, B);
    return A;
}
//https://www.interviewbit.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>
using namespace std;

ListNode *mergeTwoLists(ListNode *A, ListNode *B)
{
    ListNode *temp = new ListNode(0);
    ListNode *first = temp;
    while (A && B)
    {
        if (A->val <= B->val)
        {
            temp->next = A;
            A = A->next;
        }
        else
        {
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    if (A)
    {
        temp->next = A;
    }
    if (B)
    {
        temp->next = B;
    }
    return first->next;
}
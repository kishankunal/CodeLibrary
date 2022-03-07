//https://www.interviewbit.com/problems/rotate-list/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *A, int B)
{
    int totalNodes = 0;
    ListNode *curr = A;
    while (curr)
    {
        totalNodes++;
        curr = curr->next;
    }
    if (totalNodes == 1 || B % totalNodes == 0)
    {
        return A;
    }
    B = totalNodes - B % totalNodes;
    curr = A;
    for (int i = 0; i < B - 1; i++)
    {
        curr = curr->next;
    }
    ListNode *first = curr->next;
    curr->next = NULL;
    curr = first;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = A;
    return first;
}
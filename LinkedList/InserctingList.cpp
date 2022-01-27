//https://www.interviewbit.com/problems/intersection-of-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *A, ListNode *B)
{
    ListNode *ptr1 = A;
    ListNode *ptr2 = B;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1 ? ptr1->next : B;
        ptr2 = ptr2 ? ptr2->next : A;
    }
    return ptr1;
}

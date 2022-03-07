//https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    ListNode *curr = head;
    ListNode *next = head->next;
    ListNode *temp = next->next;
    next->next = curr;
    curr->next = swapPairs(temp);
    return next;
}
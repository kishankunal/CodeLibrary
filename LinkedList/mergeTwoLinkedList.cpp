#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *getMidNode(ListNode *root)
    {

        if (!root)
            return root;
        ListNode *_midNode = root;
        ListNode *_tailNode = root;
        ListNode *_prevNode = NULL;
        while (_tailNode && _tailNode->next)
        {
            _prevNode = _midNode;
            _midNode = _midNode->next;
            _tailNode = _tailNode->next->next;
        }
        if (_prevNode)
            _prevNode->next = NULL;
        return _midNode;
    }
    ListNode *sorts(ListNode *left, ListNode *right)
    {
        if (!left && !right)
        {
            return !left ? right : left;
        }
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (left && right)
        {

            if (left->val <= right->val)
            {
                if (tail)
                {
                    tail->next = left;
                    tail = tail->next;
                }
                else
                {
                    head = left;
                    tail = left;
                }
                left = left->next;
            }
            else
            {
                if (tail)
                {
                    tail->next = right;
                    tail = tail->next;
                }
                else
                {
                    head = right;
                    tail = right;
                }
                right = right->next;
            }
        }
        if (left)
        {
            tail->next = left;
        }
        if (right)
        {
            tail->next = right;
        }
        return head;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *midNode = getMidNode(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(midNode);
        return sorts(left, right);
    }
};
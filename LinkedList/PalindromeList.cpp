//https://leetcode.com/problems/palindrome-linked-list/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next; //important line
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = reverse(slow->next);
        while (head && fast)
        {
            if (head->val != fast->val)
            {
                return false;
            }
            fast = fast->next;
            head = head->next;
        }
        return true;
    }
};
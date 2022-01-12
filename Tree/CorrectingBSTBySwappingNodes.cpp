#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
    TreeNode(int x)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = x;
    }
};

class solution
{
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;
    void inorder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        if (prev && root->val < prev->val)
        {
            if(!first){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    //after this swap the values of first and middle or first and last
};
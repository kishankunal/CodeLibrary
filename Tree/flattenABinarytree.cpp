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

TreeNode* flat(TreeNode *root){
    stack<TreeNode *> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode *tp = stk.top();
        stk.pop();
        if(tp->right){
            stk.push(tp->right);
        }
        if(tp->left){
            stk.push(tp->left);
        }
        if(!stk.empty()){
            tp->right = stk.top();
        }
        tp->left = NULL;
    }
}

TreeNode* flat(TreeNode *root){
    TreeNode *curr = root;
    while(curr){
        if(curr->left){
            TreeNode *pre = curr->left;
            while(pre->right){
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr->right;
    }
}
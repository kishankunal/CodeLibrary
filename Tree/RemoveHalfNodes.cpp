//https://www.interviewbit.com/problems/remove-half-nodes/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

TreeNode* solve(TreeNode* root) {
    if(!root){
        return root;
    }
    root->left = solve(root->left);
    root->right = solve(root->right);
    if(!root->left && !root->right){
        return root;
    }
    if(!root->right){
        return root->left;
    }
    if(!root->left){
        return root->right;
    }
    return root;
}

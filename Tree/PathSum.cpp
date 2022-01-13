//https://www.interviewbit.com/problems/path-sum/

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

bool sum(TreeNode *root, int b, int s){
    if(!root){
        return false;
    }
    if(!root->left && !root->right && b == s + root->val){
        return true;
    }
    return sum(root->left, b, s+root->val) || sum(root->right, b, s+root->val);
}
int hasPathSum(TreeNode* A, int B) {
    if(sum(A, B, 0)){
        return 1;
    }
    return 0;
}
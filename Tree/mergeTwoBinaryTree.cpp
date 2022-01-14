//https://www.interviewbit.com/problems/merge-two-binary-tree/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int val = 0;
};

TreeNode* solve(TreeNode* A, TreeNode* B) {
    if(!A){
        return B;
    }
    if(!B){
        return A;
    }
    A->val += B->val;
    A->left = solve(A->left, B->left);
    A->right = solve(A->right, B->right);
    return A;
}
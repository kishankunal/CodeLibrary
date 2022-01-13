//https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
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
void inorder(TreeNode *root, int &B, int &n){
    if(!root){
        return;
    }
    inorder(root->left, B, n);
   B--;
    if(B==0){
       
        n = root->val;
    }
    inorder(root->right, B, n);
}
int kthsmallest(TreeNode* A, int B) {
    int n = -1;
    inorder(A, B, n);
    return n;
}
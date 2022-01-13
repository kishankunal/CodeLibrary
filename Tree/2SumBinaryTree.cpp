//https://www.interviewbit.com/problems/2sum-binary-tree/
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

void in(TreeNode *A, vector<int> &n){
     if(!A){
         return;
     }
     in(A->left, n);
     n.push_back(A->val);
     in(A->right, n);
 }
int t2Sum(TreeNode* A, int B) {
    vector<int> inorder;
    in(A, inorder);
    int i = 0;
    int j = inorder.size()-1;
    while(i<j){
        int target = inorder[i] + inorder[j];
        if(target == B){
            return 1;
        }
        else{
            if(target>B){
                j--;
            }
            else{
                i++;
            }
        }
    }
    return 0;
}

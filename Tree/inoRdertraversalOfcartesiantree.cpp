//https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

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


TreeNode *buildtree(vector<int> &A, int s, int n){
    if(s>n){
        return NULL;
    }
    int maxIndex = -1;
    int maxm = -1;
    int i ;
   for(i = s ; i<=n; i++){
       if(maxm < A[i]){
           maxm = A[i];
           maxIndex = i;
       }
   }
   TreeNode *root = new TreeNode(A[maxIndex]);
   root->left = buildtree(A, s, maxIndex-1);
   root->right = buildtree(A, maxIndex+1, n);
   return root;
}
TreeNode* buildTree(vector<int> &A) {
    if(A.size() == 0) return NULL;
   return buildtree(A,0, A.size()-1);
}


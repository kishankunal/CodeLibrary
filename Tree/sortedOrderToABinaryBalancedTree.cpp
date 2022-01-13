//https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
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

TreeNode *build(const vector<int> &A, int start, int end){
     if(start > end){
         return NULL;
     }
     int middle = (start + end);
     if(middle%2==0){
         middle >>= 1;
     }
     else{
         middle >>= 1;
         middle++;
     }
     TreeNode *root = new TreeNode(A[middle]);
     root->left = build(A, start, middle-1);
     root->right = build(A, middle+1, end);
     return root;
 }
TreeNode* sortedArrayToBST(const vector<int> &A) {
    return build(A, 0, A.size()-1);
}

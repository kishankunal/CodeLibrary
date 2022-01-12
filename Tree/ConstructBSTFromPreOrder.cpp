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

TreeNode* BSTFromPreOrder(vector<int> &A, int i, int Upperval =  INT_MAX){
    if(i == A.size() || A[i] > Upperval){
        return NULL;
    }
    TreeNode *root  = new TreeNode(A[i++]);
    root->left = BSTFromPreOrder(A, i, root->val);
    root->right = BSTFromPreOrder(A, i, Upperval);
    return root;
}
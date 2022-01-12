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

int InorderSuc(TreeNode *root, TreeNode *p){
    int suc = INT_MAX;
    while(root){
        if(p->val >= root->val){
            root= root->right;
        }
        else{
            suc = root->val;
            root= root->left;
        }
    }
    return suc;
}
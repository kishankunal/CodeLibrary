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

vector<int> inorder(TreeNode* root){
    vector<int> inorder;
    TreeNode *curr = root;
    while(curr){
        if(!curr->left){ 
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode *prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                //for preorder
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}
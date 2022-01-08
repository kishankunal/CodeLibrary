#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

void inorder(treeNode* root, vector<int> &res){
        if(!root){
            return;
        }
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(treeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
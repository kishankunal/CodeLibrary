//https://www.codingninjas.com/codestudio/problems/remove-half-nodes_920754?leftPanelTab=1
#include<bits/stdc++.h>
using namespace std;

Node* removeHalfNodes(Node *root)
{
    if(!root){
        return root;
    }
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    if(!root->left && !root->right){
        return root;
    }
    if(!root->left){
        return root->right;
    }
    if(!root->right){
        return root->left;
    }
    return root;
}
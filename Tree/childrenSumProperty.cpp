#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

void ChangeTree(treeNode * root){
    if(!root){
        return ;
    }
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }
    if(child >= root->data){
        root->data = child;
    }
    else{
        if(root->left){
            root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }
    ChangeTree(root->left);
    ChangeTree(root->right);
    int tot = 0;
    if(root->left){
        tot += root->left->data;
    }
    if(root->right){
        tot += root->right->data;
    }
    if(root->left || root->right){
        root->data = tot;
    }
}
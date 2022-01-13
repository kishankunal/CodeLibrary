#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

treeNode* lowestCommonAncestor(treeNode* root, treeNode *a, treeNode* b){
    if(!root || root == a || root == b){
        return root;
    }
    treeNode *left = lowestCommonAncestor(root->left, a, b);
    treeNode *right = lowestCommonAncestor(root->right, a, b);
    if(!left){
        return right;
    }
    else if(!right){
        return left;
    }
    else{//here lies the result
        return root;
    }
}
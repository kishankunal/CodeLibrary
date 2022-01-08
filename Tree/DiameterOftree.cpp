#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};



int maxDepth(treeNode* root, int maxm){
    if(!root){
        return 0;
    }
    int lh = maxDepth(root->left, maxm);
    int rh =  maxDepth(root->right, maxm);
    maxm =1+  max(maxm, lh+rh);
    return 1 + max(lh,rh);
}
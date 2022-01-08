#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};


//for every node height of left - height of right <= 1
int maxDepth(treeNode* root){
    if(!root){
        return 0;
    }
    int lh = maxDepth(root->left);
    if(lh==-1){
        return -1;
    }
    int rh =  maxDepth(root->right);
    if(rh == -1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1 + max(lh,rh);
}
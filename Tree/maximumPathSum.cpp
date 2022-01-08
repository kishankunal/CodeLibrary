#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

int maxpathSum(treeNode *root, int maxm){
    if(!root){
        return 0;
    }
    int ls = maxpathSum(root->left,maxm);
    int rs = maxpathSum(root->right,maxm);
    maxm = max(maxm, root->data+ls+rs);
    return root->data + max(ls, rs);
}
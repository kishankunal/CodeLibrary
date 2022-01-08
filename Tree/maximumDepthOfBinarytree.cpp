#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

int maxDepth(treeNode* root){
    if(!root){
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    
}
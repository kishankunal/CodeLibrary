#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

bool sameTree(treeNode *a, treeNode* b){
    if(!a || !b){
        return (a==b);
    }
    return (a->data == b->data) && sameTree(a->left, b->left) && sameTree(a->right, b->right);
}
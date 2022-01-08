#include <bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode *left = NULL;
    treeNode *right = NULL;
    int data = 0;
};

void pre(treeNode *root, vector<int> &preOrder)
{
    if (!root)
    {
        return;
    }
    preOrder.push_back(root->data);
    pre(root->left, preOrder);
    pre(root->right, preOrder);
}

vector<int> preorderTraversal(treeNode *root)
{
    vector<int> preOrder;
    pre(root, preOrder);
    return preOrder;
}
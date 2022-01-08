#include <bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode *left = NULL;
    treeNode *right = NULL;
    int data = 0;
};

bool leaf(treeNode *root)
{
    if (!root->left && !root->right)
    {
        return true;
    }
    return false;
}

void fillLeftboundary(treeNode *root, vector<int> &res)
{
    treeNode *curr = root->left;
    while (curr)
    {
        if (!leaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void fillLeaves(treeNode *root, vector<int> &res)
{
    if (leaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
    {
        fillLeaves(root->left, res);
    }
    if (root->right)
    {
        fillLeaves(root->right, res);
    }
}
void fillRightBoundary(treeNode *root, vector<int> &res)
{
    treeNode *curr = root->right;
    stack<int> stk;
    while (curr)
    {
        if (!leaf(curr))
        {
            stk.push(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    while(!stk.empty){
        res.push_back(stk.top());
        stk.pop();
    }
}

vector<int> printBoundry(treeNode *root)
{
    vector<int> res;
    if (!root)
    {
        return res;
    }
    //anticockwise
    if (!leaf(root))
    {
        res.push_back(root->data);
    }
    fillLeftboundary(root, res);
    fillLeaves(root, res);
    fillRightBoundary(root, res);
    return res;
}
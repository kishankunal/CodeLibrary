//https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

bool valid(BinaryTreeNode<int> *root, int min, int max)
{
    if (!root)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    return valid(root->left, min, root->data) && valid(root->right, root->data, max);
}

bool validateBST(BinaryTreeNode<int> *root)
{
    return valid(root, INT_MIN, INT_MAX);
}
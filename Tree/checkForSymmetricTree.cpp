#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

bool isSymmetric(TreeNode *root)
{
    return !root || symHelper(root->left, root->right);
}
bool symHelper(TreeNode *r1, TreeNode *r2)
{
    if (r1 == NULL || r2 == NULL)
    {
        return r1 == r2;
    }
    if (r1->val != r2->val)
    {
        return false;
    }
    return symHelper(r1->left, r2->right) && symHelper(r1->right, r2->left);
}
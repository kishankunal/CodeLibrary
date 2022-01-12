#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
    TreeNode(int x)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = x;
    }
};
//inorder and preorder is given
TreeNode *buildTree(vector<int> &preOrder, vector<int> &inorder)
{
    map<int, int> inMap;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        inMap[inorder[i]] = i;
    }
    return buildTree(preOrder, 0, n - 1, inorder, 0, n - 1, inMap);
}

TreeNode *buildTree(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> mp)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preOrder[preStart]);
    int inRoot = mp[root->val];
    int numLeft = inRoot - inStart;
    root->left = buildTree(preOrder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mp);
    root->right = buildTree(preOrder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);
    return root;
}
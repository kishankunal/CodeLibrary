//https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


void inorder(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    vector<int> ans;
    inorder(root, ans);
    int i = 0;
    int j = ans.size() - 1;
    while (i < j)
    {
        int x = ans[i] + ans[j];
        if (x == target)
        {
            return true;
        }
        else if (x > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
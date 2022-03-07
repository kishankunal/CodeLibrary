//https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?leftPanelTab=2
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

#include <bits/stdc++.h>
using namespace std;
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> leftView;
    vector<int> rightView;
    map<int, vector<int>> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode<int> *front = q.front().first;
            int level = q.front().second;
            q.pop();
            if (!front->left && !front->right)
            {
                mp[level].push_back(front->data);
            }
            else if (i == 0)
            {
                leftView.push_back(front->data);
            }
            else if (i == n - 1)
            {
                rightView.push_back(front->data);
            }
            if (front->left)
            {
                q.push({front->left, level - 1});
            }
            if (front->right)
            {
                q.push({front->right, level + 1});
            }
        }
    }
    reverse(rightView.begin(), rightView.end());
    for (auto a : mp)
    {
        leftView.insert(leftView.end(), a.second.begin(), a.second.end());
    }
    leftView.insert(leftView.end(), rightView.begin(), rightView.end());

    return leftView;
}
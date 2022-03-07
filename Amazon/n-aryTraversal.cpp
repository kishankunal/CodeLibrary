//https://www.codingninjas.com/codestudio/problems/n-ary-tree-level-order-traversal_1281306?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

vector<int> levelOrder(TreeNode<int> *root)
{
    vector<int> ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode<int> *front = q.front();
            q.pop();
            ans.push_back(front->data);
            vector<TreeNode<int> *> child = front->child;
            for (int j = 0; j < child.size(); j++)
            {
                q.push(child[j]);
            }
        }
    }
    return ans;
}
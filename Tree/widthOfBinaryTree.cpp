#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int width = 0;
    while (!q.empty())
    {
        int n = q.size();
        int mmin = q.front().second;
        int x, y;
        for (int i = 0; i < n; i++)
        {
            TreeNode *top = q.front().first;
            int val = q.front().second - mmin;
            q.pop();
            if (i == 0)
            {
                x = val;
            }
            if (i == n - 1)
            {
                y = val;
                width = max(width, abs(x - y) + 1);
            }
            if (top->left)
            {
                q.push({top->left, 2 * val + 1});
            }
            if (top->right)
            {
                q.push({top->right, 2 * val + 2});
            }
        }
    }
    return width;
}
//
#include <bits/stdc++.h>
using namespace std;

int r[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int c[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dfs(int n, int m, int x, int y, vector<vector<int>> &grid)
{
    if (!(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1))
    {
        return 0;
    }
    grid[x][y] = 0;
    int ans = 1;
    for (int i = 0; i < 8; i++)
    {
        ans += dfs(n, m, x + r[i], y + c[i], grid);
    }
    return ans;
}
int findMaxArea(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ans = max(ans, dfs(n, m, i, j, grid));
            }
        }
    }
    return ans;
}
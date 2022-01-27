//https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/0/?track=DSASP-Graph&batchId=183
#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &grid, int x, int y, int n, int m, bool **visited)
{
    if ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (grid[x][y]) && !visited[x][y])
    {
        return true;
    }
    return false;
}
void area(vector<vector<int>> &grid, int x, int y, int n, int m, int &count, bool **visited)
{
    visited[x][y] = true;
    static int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++)
    {
        if (isValid(grid, x + r[i], y + c[i], n, m, visited))
        {
            count++;
            area(grid, x + r[i], y + c[i], n, m, count, visited);
        }
    }
}
int findMaxArea(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !visited[i][j])
            {
                int res = 1;
                area(grid, i, j, n, m, res, visited);
                count = max(count, res);
            }
        }
    }
    return count;
}
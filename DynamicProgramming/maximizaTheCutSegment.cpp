//https://practice.geeksforgeeks.org/problems/cutted-segments1642/0/?track=DSASP-DP&batchId=183#
#include <bits/stdc++.h>
using namespace std;

int maxm(int n, int x, int y, int z, int *dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n == 0)
    {
        return dp[n] = 0;
    }
    int res1 = INT_MIN;
    int res2 = INT_MIN;
    int res3 = INT_MIN;
    if (n - x >= 0)
    {
        res1 = maxm(n - x, x, y, z, dp);
    }
    if (n - y >= 0)
    {
        res2 = maxm(n - y, x, y, z, dp);
    }
    if (n - z >= 0)
    {
        res3 = maxm(n - z, x, y, z, dp);
    }

    return dp[n] = 1 + max(res1, max(res2, res3));
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    int ans = maxm(n, x, y, z, dp);
    if (ans < 0)
    {
        return 0;
    }
    return ans;
}
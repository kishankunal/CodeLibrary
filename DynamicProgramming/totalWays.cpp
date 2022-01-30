//
#include <bits/stdc++.h>
using namespace std;

int totalWays(int *coins, int n, int sum, int **dp)
{
    if (dp[sum][n] != -1)
    {
        return dp[sum][n];
    }
    if (sum == 0)
    {
        dp[sum][n] = 1;
    }
    else if (n <= 0)
    {
        dp[sum][n] = 0;
    }
    else
    {
        dp[sum][n] = (totalWays(coins, n - 1, sum, dp)) % 1000000007;
        if (sum >= coins[n - 1])
        {
            dp[sum][n] += (totalWays(coins, n, sum - coins[n - 1], dp)) % 1000000007;
        }
    }
    return dp[sum][n] % 1000000007;
}
int countWays(int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    int coins[n - 2];
    for (int k = 1; k < n; k++)
    {
        coins[k - 1] = k;
    }
    return totalWays(coins, n - 1, n, dp);
}
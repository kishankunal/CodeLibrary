//https://practice.geeksforgeeks.org/problems/coin-change-minimum-number-of-coins/0/?track=DSASP-DP&batchId=183
#include <bits/stdc++.h>
using namespace std;

long long minimumNumberOfCoins(int coins[], int n, int v)
{
    int dp[v + 1];
    dp[0] = 0;
    for (int i = 1; i <= v; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int subRes = dp[i - coins[j]];
                if (subRes != INT_MAX)
                {
                    dp[i] = min(dp[i], subRes + 1);
                }
            }
        }
    }
    if (dp[v] != INT_MAX)
    {
        return dp[v];
    }
    return -1;
}
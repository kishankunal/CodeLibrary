//https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/0/?track=DSASP-DP&batchId=183
//order matter
#include <bits/stdc++.h>
using namespace std;
int countWays(int n, long long int *dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n == 0 || n == 1)
    {
        dp[n] = 1;
    }
    else
    {
        dp[n] = (countWays(n - 1, dp) % 1000000007 + countWays(n - 2, dp) % 1000000007) % 1000000007;
    }

    return dp[n] % 1000000007;
}
int countWays(int n)
{
    long long int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    return countWays(n, dp);
}

//https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/0/?track=DSASP-DP&batchId=183#
//order does not matter
long long countWays(int m)
{
    return 1 + (m / 2);
}
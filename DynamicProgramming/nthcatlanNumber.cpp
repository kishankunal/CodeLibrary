//https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/0/?track=DSASP-DP&batchId=183

#include <bits/stdc++.h>
using namespace std;

cpp_int findCatalan(int n)
{
    cpp_int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}
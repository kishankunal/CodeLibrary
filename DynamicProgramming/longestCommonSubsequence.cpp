//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/0/?track=DSASP-DP&batchId=183#
#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{
    int **dp = new int *[x + 1];
    for (int i = 0; i <= x; i++)
    {
        dp[i] = new int[y + 1];
        for (int j = 0; j <= y; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
}
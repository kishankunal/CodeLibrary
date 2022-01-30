//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/0/?track=DSASP-DP&batchId=183
#include <bits/stdc++.h>
using namespace std;

int Lis(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
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
    return dp[m][n];
}
int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    int lis = Lis(X, Y, m, n);
    m = m - lis;
    n = n - lis;
    int res = lis + m + n;
    return res;
}
//https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/0/?track=DSASP-DP&batchId=183
#include <bits/stdc++.h>
using namespace std;

int num(int m, int n, int **dp)
{
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (m == 1 || n == 1)
    {
        dp[m][n] = 1;
    }
    else
    {
        dp[m][n] = num(m - 1, n, dp) + num(m, n - 1, dp);
    }
    return dp[m][n];
}
//Function to find total number of unique paths.
int NumberOfPath(int a, int b)
{
    int **dp = new int *[a + 1];
    for (int i = 0; i <= a; i++)
    {
        dp[i] = new int[b + 1];
        for (int j = 0; j <= b; j++)
        {
            dp[i][j] = -1;
        }
    }
    return num(a, b, dp);
}
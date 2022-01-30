//https://practice.geeksforgeeks.org/problems/fibonacci-numbers-bottom-up-dp/1/?track=DSASP-DP&batchId=183#
#include <bits/stdc++.h>
using namespace std;

long long fib(int n, long long *dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n == 1 || n == 2)
    {
        dp[n] = 1;
    }
    else
    {
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    }
    return dp[n];
}

long long findNthFibonacci(int n)
{
    long long *dp = new long long[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    return fib(n, dp);
}
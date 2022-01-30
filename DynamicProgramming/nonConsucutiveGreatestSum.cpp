//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-ii/0/?track=DSASP-DP&batchId=183#
#include <bits/stdc++.h>
using namespace std;

long long maximumSum(int arr[], int n)
{
    long long int kadane[n] = {0};
    kadane[0] = max((long long)arr[0], kadane[0]);
    kadane[1] = max(kadane[0], (long long)arr[1]);
    for (int i = 2; i < n; i++)
    {
        kadane[i] = max(kadane[i - 2] + arr[i], kadane[i - 1]);
    }
    long long maxx = INT_MIN;
    bool isAllNegative = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            isAllNegative = false;
            break;
        }
        maxx = max(maxx, (long long)arr[i]);
    }
    if (isAllNegative)
    {
        return maxx;
    }
    return kadane[n - 1];
}
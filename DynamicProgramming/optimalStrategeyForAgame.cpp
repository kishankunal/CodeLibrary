//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/0/?track=DSASP-DP&batchId=183#
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int memo[MAX][MAX];

int oSRec(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);

    if (memo[i][j] != -1)
        return memo[i][j];

    memo[i][j] = max((sum - oSRec(arr, i + 1, j, sum - arr[i])),
                     (sum - oSRec(arr, i, j - 1, sum - arr[j])));

    return memo[i][j];
}
long long maximumAmount(int arr[], int n)
{
    int sum = 0;
    sum = accumulate(arr, arr + n, sum);

    memset(memo, -1, sizeof(memo));

    return oSRec(arr, 0, n - 1, sum);
}
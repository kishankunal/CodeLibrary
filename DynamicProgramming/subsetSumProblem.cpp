
#include<bits/stdc++.h>
using namespace std;

int subsetSum(int *arr, int n, int sum, int **dp){
    if(dp[n][sum]!= -1){
        return dp[n][sum];
    }
    if(n == 0){
        return dp[n][sum] = sum == 0 ? 1 : 0;
    }

    return dp[n][sum] = subsetSum(arr, n-1, sum) + subsetSum(arr, n-1, sum - arr[i]);
}
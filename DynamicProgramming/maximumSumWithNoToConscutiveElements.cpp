
#include<bits/stdc++.h>
using namespace std;


int maximumSum(int *arr, int n, int *dp){
    if(dp[n] != -1){
        return dp[n];
    }
    if(n==1){
        return dp[n] = arr[0];
    }
    if(n == 2){
        return dp[n] = max(arr[0], arr[1]);
    }
    return dp[n] = max(maximumSum(arr, n-1), arr[n-1] + maximumSum(arr, n-2));
}

//using tabelization constant space

int maxSum(int *arr, int sum){
    int prev_prev = arr[0];
    int prev = max(arr[0]. arr[1]);
    int res = prev;
    for(int i = 2; i<n; i++){
        res = max(prev, prev_prev + arr[i]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}
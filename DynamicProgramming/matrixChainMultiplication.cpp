
#include<bits/stdc++.h>
using namespace std;


int mult(int *arr, int i, int j, int **dp){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == j + 1){
        return dp[i][j] = 0;
    }
    int res = INT_MAX;
    for(int k = i+1; k<j; k++){
        res = min(res, mult(arr, i, k) + mult(arr, k, j) + arr[i] * arr[j] * arr[k]);
    }
    return dp[i][j] = res;
}
// ans will be at dp[0][n-1]
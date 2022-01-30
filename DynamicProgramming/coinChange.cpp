//https://practice.geeksforgeeks.org/problems/coin-change-number-of-ways/0/?track=DSASP-DP&batchId=183#
#include<bits/stdc++.h>
using namespace std;

long long coinChange(int *coins, int n, int v, int **dp){
    if(dp[v][n] != -1){
        return dp[v][n];
    }
    if(n <= 0){
        dp[v][n] = 0;
    }
    else if(v == 0){
        dp[v][n] = 1;
    }
    else{
        dp[v][n] = coinChange(coins, n-1, v, dp);
        if(v-coins[n-1] >= 0){
            dp[v][n] += coinChange(coins, n, v-coins[n-1], dp);
         }
    }
    
    return dp[v][n];
}
long long numberOfWays(int coins[],int n,int v)
    {
        int **dp = new int*[v+1];
        for(int i = 0; i<=v; i++){
            dp[i] = new int[n+1];
            for(int j = 0; j<=n; j++){
                dp[i][j] = -1;
            }
        }
        return coinChange(coins, n, v, dp);
    }
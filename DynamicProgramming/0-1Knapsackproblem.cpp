//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/0/?track=DSASP-DP&batchId=183#
#include<bits/stdc++.h>
using namespace std;


int maxValue(int w, int *wt, int *val, int n, int **dp){
        if(dp[n][w]== -1){
            if(w == 0 || n == 0){
                dp[n][w] = 0;
            }
            else if(wt[n-1] > w){
                dp[n][w] = maxValue(w, wt, val, n-1, dp);
            }
            else{
                dp[n][w] = max(maxValue(w, wt, val, n-1, dp), val[n-1] + maxValue(w-wt[n-1], wt, val, n-1, dp));
            }
        }
        return dp[n][w];
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
      int **dp = new int*[n + 1];
       for(int i = 0; i<= n; i++){
           dp[i] = new int[w+1];
           for(int j = 0; j<=w; j++){
               dp[i][j] = -1;
           }
       }
        return maxValue(w, wt, val, n, dp); 
    }
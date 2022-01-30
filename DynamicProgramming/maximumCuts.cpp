
#include<bits/stdc++.h>
using namespace std;


int maximumCuts(int n, int a, int b, int c, int *dp){
    if(dp[n] != -1){
        return dp[n];
    }
    if(n < 0){
        return dp[n] = -1;
    }
    if(n == 0){
        return dp[n] = 0;
    }
    int res = max(maximumCuts(n-a, a, b, c, dp), max(maximumCuts(n-b, a, b, c, dp), maximumCuts(n-c, a, b, c, dp)));
    if(res  == -1){
        return dp[n] = -1;
    }
    return dp[n] = res + 1;
}
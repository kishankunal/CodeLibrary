
#include<bits/stdc++.h>
using namespace std;


int egg(int floor, int egg, int n, int **dp){
    if(dp[floor][egg] != -1){
        return dp[egg][floor];
    }
    if(floor == 0 || floor == 1 || egg == 1){
        return dp[egg][floor] = floor;
    }
    return dp[egg][floor] = min(egg(floor - 1, egg - 1), egg(n - floor, egg) + 1);
}
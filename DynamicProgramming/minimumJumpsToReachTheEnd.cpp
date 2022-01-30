
#include<bits/stdc++.h>
using namespace std;

int minJump(int *arrm, int n){
    int start = 0;
    int end = arr[start];
    int maxReach = end;
    int jump = 1;
    while(start < n-1){
        maxReach = max(maxReach, start + arr[start]);
        if(start == end){
            jump++;
            if(maxReach <= end){
                return -1;
            }
            end = maxReach;
        }
        start++;
    }
    return jump;
}

int minimumJumps(int *arr, int n, int *dp){
    if(dp[n] !=INT_MAX){
        return dp[n];
    }
    if(n == 1){
        return dp[n] = 0;
    }
    
    int res = INT_MAX;
    for(int i = 0; i<n-2; i++){
        if(i + arr[i] >= n-1){
            int subRes = minimumJumps(arr, i+1, dp);
        }
        if(subRes != INT_MAX){
            res = min ( res, subRes + 1);
        }
    }
    return dp[n] = res;

}


int decideJump(int nums[], int n, int currPos){
    if(currPos >=  n-1){
        return 0;
    }
    int minJump = INT_MAX;
    int maxSteps = nums[currPos]
    while(maxSteps > 0){
        minJump = min(minJump, 1 + decideJump(nums,n,currPos+maxSteps))
        maxSteps = maxSteps - 1;
    }
    return minJump
}
   
int jump(int nums[], int n) {
    return decideJump(nums, n, 0);
}
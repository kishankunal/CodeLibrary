
#include<bits/stdc++.h>
using namespace std;
int maxm(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int longestSumIncreasingSubsequence(int arr[], int n){
    int *ls = new int(n);
    ls[0] = arr[0];
    for(int i = 1; i<n; i++){
        lis[i] = arr[i];
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j])  
                ls[i] = maxm(ls[i], (ls[j] + arr[i]));
        }
    }
    int res = ls[0];
    for(int i = 0; i<n; i++){
        res = max(ls[i], res);
    }
    return res;
}
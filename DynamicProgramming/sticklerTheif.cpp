//https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/0/?track=DSASP-DP&batchId=183

#include<bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n)
{
    int including = arr[0];
    int excluding = 0;
    int prevIncluding = 0;
    for(int i = 1; i<n; i++){
        prevIncluding = including;
        including = excluding + arr[i];
        excluding = max(excluding, prevIncluding);
    }
    return max(including, excluding);
}
//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-i/0/?track=DSASP-DP&batchId=183
#include <bits/stdc++.h>
using namespace std;

long long maximumSum(int arr[], int n)
{
    long long ans = arr[0];
    long long temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp + arr[i];
        ans = max(ans, temp);
        if (temp < 0)
        {
            temp = 0;
        }
    }
    cout << endl;
    return ans;
}
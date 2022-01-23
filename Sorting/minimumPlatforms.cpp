//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/0/?track=DSASP-Sorting&batchId=183#
#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int minm = 1;
    int temp = 1;
    int i = 1;
    int j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            i++;
            temp++;
        }
        else
        {
            j++;
            temp--;
        }
        minm = max(temp, minm);
    }
    return minm;
}
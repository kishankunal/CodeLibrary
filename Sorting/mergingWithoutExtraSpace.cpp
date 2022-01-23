//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/0/?track=DSASP-Sorting&batchId=183
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
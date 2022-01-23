//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s-1587115621/0/?track=DSASP-Sorting&batchId=183
#include <bits/stdc++.h>
using namespace std;

void segragate012(int arr[], int n)
{
    int start = -1;
    int end = n;
    for (int i = 0; i < end;)
    {
        if (arr[i] == 0)
        {
            swap(arr[i++], arr[++start]);
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[--end]);
        }
        else
        {
            i++;
        }
    }
}
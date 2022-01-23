//https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/0/?track=DSASP-Sorting&batchId=183
#include <bits/stdc++.h>
using namespace std;

int findNumberOfTriangles(int arr[], int n)
{
    sort(arr, arr + n);
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int j = 0;
        int k = i - 1;
        while (j < k)
        {
            if (arr[j] + arr[k] > arr[i])
            {
                count += k - j;
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return count;
}
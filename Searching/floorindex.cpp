//https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/0/?track=DSASP-Searching&batchId=183
#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<long long> arr, long long n, long long x)
{
    long long low = 0;
    long long high = n - 1;
    int floorIndex = -1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] <= x)
        {
            floorIndex = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return floorIndex;
}
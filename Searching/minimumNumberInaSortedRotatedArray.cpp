//https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/0/?track=DSASP-Searching&batchId=183
#include <bits/stdc++.h>
using namespace std;

int pivind(int arr[], int left, int right)
{
    while (left <= right)
    {
        if (left == right)
        {
            return left;
        }
        int mid = (left + right) >> 1;
        if (arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[left])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int minNumber(int arr[], int low, int high)
{
    int x = pivind(arr, low, high); // finding pivot
    if (x == -1)
    {
        return arr[0];
    }
    else
    {
        return arr[((x + 1) % (high + 1))];
    }
}
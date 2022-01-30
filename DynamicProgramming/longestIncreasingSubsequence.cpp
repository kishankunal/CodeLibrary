
#include <bits/stdc++.h>
using namespace std;

//time complexity is O(n^2)
int longestIncreasingSubsequence(int *arr, int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int res = lis[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, lis[i]);
    }
    return res;
}

//time complexity is O(nlogn) using binary Search

int findCiel(int val, int left, int right, vector<int> arr)
{
    int res = -1;
    while (left <= right)
    {
        int mid = left + right >> 1;
        if (arr[mid] >= val)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

int LIS(int *arr, int n)
{
    int res[n];
    res[0] = arr[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (res[len - 1] < arr[i])
        {
            res[len++] = arr[i];
        }
        else
        {
            int findCeil = finds(res, 0, len - 1, arr[i]);
            res[findCeil] = arr[i];
        }
    }
    return len;
}
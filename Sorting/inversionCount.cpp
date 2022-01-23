//https://practice.geeksforgeeks.org/viewSol.php?subId=079deafb250e794e78c27e2ea44a15a9&pid=701226&user=kkunal
#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, long long l, long long mid, long long h)
{
    long long temp[h - l + 1];
    long long i = l;
    long long j = mid;
    long long k = 0;
    long long result = 0;
    while (i < mid && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            result += mid - i;
            temp[k++] = arr[j++];
        }
    }
    while (i < mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    for (long long u = l; u <= h; u++)
    {
        arr[u] = temp[k++];
    }
    return result;
}

long long mergesort(long long *arr, long long l, long long h)
{
    long long result = 0;
    if (l < h)
    {
        int mid = (l + h) >> 1;
        result += mergesort(arr, l, mid);
        result += mergesort(arr, mid + 1, h);
        result += merge(arr, l, mid + 1, h);
    }
    return result;
}
long long int inversionCount(long long arr[], long long N)
{
    return mergesort(arr, 0, N - 1);
}
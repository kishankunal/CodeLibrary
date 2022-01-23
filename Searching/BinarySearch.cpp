#include <bits/stdc++.h>
using namespace std;

int searchInSorted(int arr[], int n, int K)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == K)
        {
            return mid;
        }
        else if (arr[mid] > K)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
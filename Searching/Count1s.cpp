#include <bits/stdc++.h>
using namespace std;

int countOnes(int arr[], int n)
{
    int low = 0;
    int high = n;
    while (high >= low)
    {
        int mid = (high + low) >> 1;
        if (arr[mid] == 1 && (mid == (n - 1) || arr[mid + 1] == 0))
        {
            return (mid + 1);
        }
        if (arr[mid] < 1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}
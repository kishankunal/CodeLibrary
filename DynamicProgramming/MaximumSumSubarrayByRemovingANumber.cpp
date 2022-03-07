//
#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int A[], int n)
{

    int temp = INT_MIN;
    int sum = 0;
    int forward[n];
    int max_element = arr[i];
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        sum = max(temp, sum)
        forward[i] = sum;
        if (temp < 0)
        {
            temp = 0;
        }
        max_element = max(arr[i], max_element);
    }
    int backward[n];
    sum = 0;
    temp = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        temp += arr[i];
        sum = max(sum, temp);
        sum = max_ending_here;
        backward[i] = sum;
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        res = max(res, max(forward[i - 1], 0) + max(0, backward[i + 1]));
    }
    if (res == 0) // all neagative eleentns
        return max_element;
    return res;
}

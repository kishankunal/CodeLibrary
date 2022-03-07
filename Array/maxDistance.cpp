//https://www.interviewbit.com/problems/max-distance/
#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A)
{
    int n = A.size();
    int right[n];
    right[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], A[i]);
    }
    int ans = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        if (A[i] <= right[j])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
            i++;
    }
    return ans;
}


//sort the number
//now find min of the index of the sorted number;
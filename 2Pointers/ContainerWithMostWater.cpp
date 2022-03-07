//https://www.interviewbit.com/problems/container-with-most-water/
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &A)
{
    int i = 0;
    int j = A.size() - 1;
    int water = 0;
    while (i < j)
    {
        water = max(water, min(A[i], A[j]) * (j - i));
        if (A[i] < A[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return water;
}
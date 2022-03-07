//https://www.interviewbit.com/problems/pair-with-given-difference/
#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B)
{
    if (A.empty())
    {
        return 0;
    }
    sort(A.begin(), A.end());
    int i = 0;
    int j = 1;
    while (i < A.size() && j < A.size())
    {
        int diff = A[j] - A[i];
        if (diff == B && i != j)
        {
            return 1;
        }
        else if (diff > B)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return 0;
}

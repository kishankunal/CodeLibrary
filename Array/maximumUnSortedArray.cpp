//https://www.interviewbit.com/problems/maximum-unsorted-subarray/

#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::subUnsort(vector<int> &A)
{
    vector<int> x(A);
    sort(A.begin(), A.end());
    int start = -1;
    int end = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != x[i])
        {
            if (start == -1)
            {
                start = i;
            }
            else
            {
                end = i;
            }
        }
    }
    vector<int> ans;
    if (start != -1)
    {
        ans.push_back(start);
        ans.push_back(end);
    }
    else
    {
        ans.push_back(-1);
    }

    return ans;
}
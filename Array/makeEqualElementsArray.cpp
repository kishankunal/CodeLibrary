//https://www.interviewbit.com/problems/make-equal-elements-array/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    map<int, int> data;
    for (int i = 0; i < A.size(); i++)
    {
        data[A[i]]++;
        data[A[i] - B]++;
        data[A[i] + B]++;
    }
    for (pair<int, int> x : data)
    {
        if (x.second == A.size())
        {
            return 1;
        }
    }
    return 0;
}

int Solve(vector<int> &A, int B)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        int diff = abs(A[i] - A[i + 1]);
        if (diff % B != 0){
            return 0;
        }
    }
    return 1;
}
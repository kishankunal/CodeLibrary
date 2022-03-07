//https://www.interviewbit.com/problems/set-matrix-zeros/
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    map<int, int> r, c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
            {
                r[i] = 1;
                c[j] = 1;
            }
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (c[j] == 1 || r[i] == 1)
            {
                A[i][j] = 0;
            }
        }
    }
}
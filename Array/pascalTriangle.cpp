//https://www.interviewbit.com/problems/pascal-triangle/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Solution::solve(int A)
{
    vector<vector<int>> ans;
    for (int i = 0; i < A; i++)
    {
        if (i == 0)
        {
            vector<int> a;
            a.push_back(1);
            ans.push_back(a);
        }
        else if (i == 1)
        {
            vector<int> a;
            a.push_back(1);
            a.push_back(1);
            ans.push_back(a);
        }
        else
        {
            vector<int> a(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                a[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans.push_back(a);
        }
    }
    return ans;
}

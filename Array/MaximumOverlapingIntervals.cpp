//https://www.interviewbit.com/problems/merge-overlapping-intervals/

#include <bits/stdc++.h>
using namespace std;

vector<Interval> Solution::merge(vector<Interval> &A)
{
    vector<Interval> x;
    multimap<int, int> data;
    for (int i = 0; i < A.size(); i++)
    {
        data.insert({A[i].start, A[i].end});
    }
    int start = -1;
    int end = -1;
    for (pair<int, int> X : data)
    {
        if (start == -1)
        {
            start = X.first;
            end = X.second;
        }
        else
        {
            if (X.first > end)
            {
                Interval Y;
                Y.start = start;
                Y.end = end;
                x.push_back(Y);
                start = X.first;
                end = X.second;
            }
            else
            {
                end = max(end, X.second);
            }
        }
    }
    Interval Y;
    Y.start = start;
    Y.end = end;
    x.push_back(Y);
    return x;
}
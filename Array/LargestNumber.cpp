//https://www.interviewbit.com/problems/largest-number/
#include <bits/stdc++.h>
using namespace std;

bool com(const int &a, const int &b)
{
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1 > s2;
}
string Solution::largestNumber(const vector<int> &y)
{
    vector<int> A;
    for (int x : y)
    {
        A.push_back(x);
    }
    sort(A.begin(), A.end(), com);
    string s = "";
    if (A[0] == 0)
    {
        return "0";
    }
    for (int x : A)
    {
        s += to_string(x);
    }
    return s;
}

//https://leetcode.com/problems/single-number-iii/submissions/
#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    vector<int> ans;
    long xors = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xors = xors ^ nums[i];
    }
    long x = 0;
    long y = 0;
    long rightMostSetBit = xors & ~(xors - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & rightMostSetBit)
        {
            x = x ^ nums[i];
        }
        else
        {
            y = y ^ nums[i];
        }
    }
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}
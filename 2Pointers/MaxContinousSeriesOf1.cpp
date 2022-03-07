//https://www.interviewbit.com/problems/maximum-ones-after-modification/
#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B)
{
    int currLeft = 0;
    int currRight = 0;
    int count = 0;
    int ans = 0;
    while (currRight < A.size())
    {
        if (count <= B)
        {
            if (A[currRight] == 0)
            {
                count++;
            }
            currRight++;
        }
        if(count > B)
        {
            if (A[currLeft] == 0)
            {
                count--;
            }
            currLeft++;
        }
        ans = max(ans, currRight - currLeft);
    }
    return ans;
}
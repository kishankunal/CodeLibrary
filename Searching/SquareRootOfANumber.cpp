//https://practice.geeksforgeeks.org/viewSol.php?subId=d4e2c28c09ab384c0cff2a15d5cc28ce&pid=700226&user=kkunal
#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    long long int left = 1;
    long long int right = x;
    long long int ans;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid*mid < x)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}
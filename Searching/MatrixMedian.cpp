#include <bits/stdc++.h>
using namespace std;

int Solution::findMedian(vector<vector<int>> &a)
{
    int l = 0, r = pow(10, 9), n = a.size(), mid, m = a[0].size(), c, q, p;
    q = (n * m) / 2;
    while (l <= r)
    {
        mid = (l + r) / 2;
        c = 0;
        for (int i = 0; i < n; i++)
            c += lower_bound(begin(a[i]), end(a[i]), mid) - begin(a[i]);
        if (c <= q)
        {
            p = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return p;
}
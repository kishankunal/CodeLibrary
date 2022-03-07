//https://leetcode.com/problems/subarray-sum-equals-k/submissions/
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[sum] = 1;
    for (auto it : arr)
    {
        sum += it;
        int find = sum - k;
        if (mp.find(find) != mp.end())
        {
            ans += mp[find];
        }
        mp[sum]++;
    }
    return ans;
}
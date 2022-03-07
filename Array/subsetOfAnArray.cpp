//https://leetcode.com/problems/subsets/submissions/
#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int index, int n)
{
    if (index == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    helper(ans, temp, nums, index + 1, n);
    temp.pop_back();
    helper(ans, temp, nums, index + 1, n);
    return;
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper(ans, temp, nums, 0, nums.size());
    return ans;
}
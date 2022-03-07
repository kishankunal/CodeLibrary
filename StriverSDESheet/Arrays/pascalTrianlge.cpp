//https://leetcode.com/problems/pascals-triangle/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if (n == 1)
        {
            return ans;
        }
        temp.clear();
        temp.push_back(1);
        temp.push_back(1);
        ans.push_back(temp);
        if (n == 2)
        {
            return ans;
        }
        for (int i = 2; i < n; i++)
        {
            temp.clear();
            int k = ans[i - 1].size();
            temp.push_back(1);
            for (int j = 1; j < k; j++)
            {
                temp.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
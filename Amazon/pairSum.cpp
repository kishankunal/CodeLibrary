//https://www.codingninjas.com/codestudio/problems/pair-sum_697295?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;
    map<int, int> data;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (data[s - arr[i]] != 0)
        {
            for (int j = 0; j < data[s - arr[i]]; j++)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(s - arr[i]);
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }
        data[arr[i]]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
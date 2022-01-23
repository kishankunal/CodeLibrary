#include <bits/stdc++.h>
using namespace std;
vector<int> subarraySum(int arr[], int n, long long s)
{
    int sum = arr[0];
    int x = 0;
    int y = 0;
    vector<int> ans;
    while (x < n && y < n)
    {
        if (sum == s)
        {
            ans.push_back(x + 1);
            ans.push_back(y + 1);
            break;
        }
        else if (sum > s)
        {
            sum -= arr[x++];
        }
        else
        {
            sum += arr[++y];
        }
    }
    if (ans.size() == 0)
    {
        ans.push_back(-1);
    }
    return ans;
}
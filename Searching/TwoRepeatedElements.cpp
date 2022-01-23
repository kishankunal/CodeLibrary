
#include <bits/stdc++.h>
using namespace std;

vector<int> twoRepeated(int arr[], int n)
{
    vector<int> ans;
    int a[n];
    for (int i = 0; i <= n; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n + 2; i++)
    {
        if (a[arr[i]] == 0)
        {
            a[arr[i]] = 1;
        }
        else
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
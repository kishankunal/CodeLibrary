///https://practice.geeksforgeeks.org/problems/k-largest-elements3736/0/?track=DSASP-Heap&batchId=183
#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.size() == k)
        {
            if (pq.top() < arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        else
        {
            pq.push(arr[i]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
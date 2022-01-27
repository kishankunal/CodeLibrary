//https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/0/?track=DSASP-Heap&batchId=183
#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(int arr[], int num, int K)
{
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + K);

    for (int i = K; i < num; ++i)
    {
        res.push_back(pq.top());
        pq.pop();

        pq.push(arr[i]);
    }

    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
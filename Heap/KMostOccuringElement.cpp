//https://practice.geeksforgeeks.org/problems/most-occurring-elements-1587115620/0/?track=DSASP-Heap&batchId=183
#include <bits/stdc++.h>
using namespace std;
int kMostFrequent(int arr[], int n, int k)
{
    unordered_map<int, int> data;
    for (int i = 0; i < n; i++)
    {
        data[arr[i]]++;
    }
    priority_queue<int, vector<int>> pq;
    for (auto x : data)
    {
        pq.push(x.second);
    }
    int freq = 0;
    while (!pq.empty() && k > 0)
    {
        k--;
        freq += pq.top();
        pq.pop();
    }
    return freq;
}
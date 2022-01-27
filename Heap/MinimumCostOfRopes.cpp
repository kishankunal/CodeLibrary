//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/0/?track=DSASP-Heap&batchId=183
#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    long long sum = 0;
    while (pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        sum += first + second;
        pq.push(first + second);
    }
    return sum;
}
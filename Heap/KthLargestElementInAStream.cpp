//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream-1587115620/0/?track=DSASP-Heap&batchId=183
#include <bits/stdc++.h>
using namespace std;

void kthLargest(int arr[], int n, int k)
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
        }// after pushing size can increase to k
        if (pq.size() == k)
        {
            cout << pq.top() << " ";
        }
        else
        {
            cout << "-1 ";
        }
    }
}
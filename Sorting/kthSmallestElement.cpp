//https://practice.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620/0/?track=DSASP-Sorting&batchId=183
#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>> q;
    for (int i = 0; i < n; i++)
    {
        if (q.size() == k)
        {
            if (q.top() > arr[i])
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        else
        {
            q.push(arr[i]);
        }
    }
    return q.top();
}


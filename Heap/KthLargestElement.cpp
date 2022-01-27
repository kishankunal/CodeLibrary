//
#include <bits/stdc++.h>
using namespace std;

int KthLargest(int arr[], int n, int k)
{
    priority_queue< int, vector<int> , greater<int>> pq;
    for(int i  = 0; i<n; i++){
        if(pq.size() == k){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        else{
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
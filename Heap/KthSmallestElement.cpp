#include<bits/stdc++.h>
using namespace std;


int kthSmallestElement(vector<int> arr, int k){
    int n = arr.size();
    priority_queue<int, vector<int>> pq;
    for(int i = 0; i<n; i++){
        if(pq.size() == k){
            if(pq.top() > arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        else{
            pq.push(arr[i]);
        }
    }
}
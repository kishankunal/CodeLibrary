#include<bits/stdc++.h>
using namespacestd;

int x (int *arr, int n, int k){
    dequeue<int> stk;
    for(int i = 0; i<k; i++){
        if(!stk.empty() && arr[stk.front()] < arr[i]){
            stk.pop_front();
        }
        stk.push_back(i);
    }
    for(int i = k; i<n; i++){
        cout << arr[stk.front()];
        while(!stk.empty() && arr[stk.front()] < arr[i]){
            stk.pop_front();
        }
        while(!stk.empty() && stk.front() < i-k){
            stk.pop_front();
        }
        stk.push_back(i);
    }
}
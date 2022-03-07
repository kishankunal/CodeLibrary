#include<bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int> &A, int B){
    int n = A.size();
    int st = 1;
    int pages = 0;
    for(int i = 0; i<n; i++){
        if(mid < A[i]){
            return false;
        }
        if(pages + A[i] > mid){
            st++;
            pages = 0;
        }
        pages += A[i];
    }
    if(st<=B){
        return true;
    }
    return false;
}

int books(vector<int> &A, int B) {
    
    int low = INT_MAX;
    int high = 0;
    int n = A.size();
    if(B > n){
        return -1;
    }
    for(int i = 0; i<n; i++){
        low = min(low, A[i]);
        high += A[i];
    }
    
    int ans = -1;
    while(high >= low){
        int mid = (low + high) >> 1;
        if(isPossible(mid, A, B)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

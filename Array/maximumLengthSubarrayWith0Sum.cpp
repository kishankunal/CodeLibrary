#include<bits/stdc++.h>
using namespace std;

int maxLength(vector<int> arr, int n){
    unordered_map<int, int> mp;
    int maxi = 0;
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(sum == 0){
            maxi = i+1;
        }
        if(mp[sum]!=mp.end()){
            maxi = max(maxi ,  i - mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    return maxi;
}
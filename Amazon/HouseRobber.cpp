//https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

long long int houseRobber(vector<int>& arr)
{
    long long int n = arr.size();
    long long int excluded = 0;
    long long int included = arr[0];
    long long int prevIncluded = 0;
    for(int i = 1; i<n-1; i++){
        prevIncluded = included;
        included = excluded + arr[i];
        excluded = max(excluded, prevIncluded);
    }
    long long int ans = max(included, excluded);
    excluded = 0;
    included = arr[1];
    prevIncluded = 0;
    for(int i = 2; i<n; i++){
        prevIncluded = included;
        included = excluded + arr[i];
        excluded = max(excluded, prevIncluded);
    }
    ans = max(ans, max(included, excluded));
    return ans;     
}
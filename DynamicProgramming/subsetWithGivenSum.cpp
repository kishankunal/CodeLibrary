#include <bits/stdc++.h>

using namespace std;
set<vector<int>> subsets;
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp, vector<int>v){
    if(target==0)
        return true;
    
    if(ind == 0)
        subsets.insert(v);
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp,v);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp,v.push_back(arr[ind]));
        
    return dp[ind][target]= notTaken||taken;
}

bool subsetSumToK(int n, int k, vector<int> &arr,vector<int>v){
    vector<vector<int> > dp(n,vector<int>(k+1,-1));
    
    return subsetSumUtil(n-1,k,arr,dp,v);
}

int main() {

  vector<int> arr;
  for(int i = 0; i<5; i++){
      arr.push_back(i+1);
  }
  int k=4;
  int n = arr.size();
    vector<int> v;
    subsets.clear();
  if(subsetSumToK(n,k,arr,v))
    cout<<"Subset with given target found";
  else 
    cout<<"Subset with given target not found";

    for(auto v : subsets){
        for(int i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
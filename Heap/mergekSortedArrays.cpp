#include <bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<int, int>a, pair<int, int> b){
        return a.first >= b.first;
    }
};


vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    int index[k];
    for(int i = 0; i<k; i++){
        index[i] = 0;
        pq.push({arr[i][0], i});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        if(index[top.second] < arr[top.second].size()-1){
            ++index[top.second];
            pq.push({arr[top.second][index[top.second]], top.second});
        }
    }
    return ans;
}
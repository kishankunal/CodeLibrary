#include<bits/stdc++.h>
using namespace std;



vector<int> topologicalSort(vector<vector<int>> &graph){
    int n = graph.size();
    int *degree = new int[n];
    for(int i = 0; i<n; i++){
        for(auto a : graph[i]){
            degree[a]++;
        }
    }
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto i : graph[x]){
            degree[i]--;
            if(degree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}
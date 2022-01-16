#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &graph, bool *visited, vector<int> &ans, int start){
    visited[start] = true;
    for(auto i : graph[start]){
        dfs(graph, visited, ans, i);
    }
    ans.push_back(start);
}

vector<int> topologicalSort(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> ans;
    bool *visited = new bool(n);
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(graph, visited, ans, i);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
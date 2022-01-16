#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int > graph[], bool *visited, int index, int parent){
    visited[index] = true;
    for(int x : graph[index]){
        if(!visited[x]){
            if(dfs(graph, visited, x, index)){
                return true;
            }
        }
        else if(x != parent){
            return true;
        }
    }
    return false;
}


int solve(int n, vector<vector<int> > &b) {
	vector<int> adj[n+1];
    for(int i=0;i<b.size();i++){
        adj[b[i][0]].push_back(b[i][1]);
        adj[b[i][1]].push_back(b[i][0]);
    }
    bool visited[n+1];
        for(int i=0;i<n+1;i++){
            visited[i]=false;
        }
    for(int i = 0; i<n; i++){
        if(!visited[i+1]){
            if(dfs(adj, visited, i+1, 0)){
                return 1;
            }
        }
    }
    return false;
}

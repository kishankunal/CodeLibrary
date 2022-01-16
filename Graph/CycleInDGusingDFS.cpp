#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<int> graph[], bool *visited, bool *dfsVisited, int start){
    visited[start] = true;
    dfsVisited[start] = true;
    for(auto i : graph[start]){
        if(!visited[i]){
            if(dfs(graph, visited, dfsVisited, i)){
                return true;
            }
        }
        else if(dfsVisited[start]){
            return true;
        }
    }
    dfsVisited[start] = false;
    return false;
}

bool isCycle(int n, vector<vector<int> > &b){
    vector<int> graph[n+1];
    for(int i = 0; i<b.size(); i++){
        graph[b[i][0]].push_back(b[i][1]);
        graph[b[i][1]].push_back(b[i][0]);
    }
    bool *visited = new bool(n);
    bool *dfsVisited = new bool(n);
    for(int i = 0; i<n; i++){
        visited[i] = false;
        dfsVisited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            if(dfs(graph, visited, dfsVisited, i)){
                return true;
            }
        }
    }
    return false;
}
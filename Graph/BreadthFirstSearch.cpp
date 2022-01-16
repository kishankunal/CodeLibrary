//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/?track=DSASP-Graph&batchId=183
#include<bits/stdc++.h>
using namespace std;


void bfs(int start, bool *visited, vector<int> &ans, vector<int> adj[]){
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        ans.push_back(x);
        q.pop();
        for(int i : adj[x]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
}

vector<int>bfsOfGraph(int V, vector<int> adj[]){
    bool *visited = new bool[V];
    for(int i = 0; i<V; i++){
        visited[i] = false;
    }
    vector<int> ans;
    bfs(0,visited,ans,adj);
    return ans;
}
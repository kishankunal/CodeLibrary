#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int,int>>> &graph, bool *visited, stack<int> &topo, int start){
    visited[start] = true;
    for(auto i : graph[start]){
        if(!visited[i.first]){
            dfs(graph, visited, topo, i.first);
        }
    }
    topo.push(start);
}



int* shortestPath(vector<vector<pair<int,int>>> &graph){
    int n = graph.size();
    bool *visited = new bool(n);
    int *dist = new int(n);
    for(int i = 0; i<n; i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    stack<int> topo;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(graph, visited, topo, i);
        }
    }
    dist[0] = 0;
    //0 is considered source node here
    while(!topo.empty()){
        int top = topo.top();
        topo.pop();
        if(dist[top] != INT_MAX){
            for(auto i : graph[top]){
                if(dist[i.first] > dist[top] + i.second){
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
    return dist;
}
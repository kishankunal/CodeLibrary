//https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> graph[], bool *visited, stack<int> &topo, int start, bool *dfsVisited){
    visited[start] = true;
    dfsVisited[start] = true;
    for(int x : graph[start]){
        if(!visited[x]){
            if(dfs(graph, visited, topo, x, dfsVisited)){
                return 1;
            }
        }
        else if (dfsVisited[x]){
            return 1;
        }
    }
    dfsVisited[start] = false;
    return false;
}
int solve(int n, vector<int> &B, vector<int> &C) {
    vector<int> graph[n+1];
    for(int i =0; i<B.size(); i++){
        graph[B[i]-1].push_back(C[i]-1);
    }
    stack<int> topo;
    bool visited[n];
    bool dfsVisited[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
        dfsVisited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            if(dfs(graph, visited, topo, i, dfsVisited)){
                return 0;
            }
        }
    }
    return 1;
}

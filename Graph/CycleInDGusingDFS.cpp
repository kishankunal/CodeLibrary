//https://www.interviewbit.com/problems/cycle-in-directed-graph/

#include<bits/stdc++.h>
using namespace std;



bool dfs(int start, vector<int> graph[], bool *visited, bool *dfsvisited){
     visited[start] = true;
     dfsvisited[start] = true;
     for(int x : graph[start]){
         if(!visited[x]){
             if(dfs(x, graph, visited, dfsvisited)){
                 return true;
             }
         }
         else if(dfsvisited[x]){
             return true;
         }
     }
     dfsvisited[start] = false;
     return false;
 }


int solve(int n, vector<vector<int> > &b) {
    vector<int> graph[n+1];
    int m = b.size();
    for(int i = 0; i<m; i++){
        graph[b[i][0]].push_back(b[i][1]);
    }
    bool visited[n+1];
    bool dfsvisited[n+1];
    for(int i = 0; i<=n; i++){
        visited[i] = false;
        dfsvisited[i] = false;
    }
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i, graph, visited, dfsvisited)){
                return 1;
            }
        }
    }
    return 0;
}
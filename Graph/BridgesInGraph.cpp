#include<bits/stdc++.h>
using namespace std;

void dfs(int start, int parent, bool *visited, int *tin, int *low, int timer, vector<int, int> graph[]){
    visited[start] = true;
    tin[start] = low[start] = timer++;
    for(auto it : graph[start]){
        if(it == parent){
            continue;
        }
        if(!visited[it]){
            dfs(it, start, visited, tin, low, timer, graph);
            //low[start] = min(low[start], low[it]);
            if(low[it] > low[start]){
                cout << start << " " << it <<endl;
            }
        }
        else{
            //low[start] = min(low[start], tin[it]);
        }
    }
}


void bridges(vector<int, int> graph[], int n){
    bool visited[n];
    int tin[n];//time of insertion
    int low[n];//mintime
    for(int i = 0; i<n; i++){
        visited[i] = false;
        tin[i] = -1;
        low[i] = -1;
    }
    int timer = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i, -1, visited, tin, low, timer, graph);
        }
    }
}
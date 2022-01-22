#include<bits/stdc++.h>
using namespace std;

void dfs(int start, int parent, vector<int> &articulationPoint, int *tin, int *low, bool *visited, int timer, vector<vector<int> > graph){
    visited[start] = true;
    low[start] = tin[start] = timer++;
    int child = 0;
    for(int x : graph[start]){
        if(!visited[x]){
            dfs(x, start, articulationPoint, tin, low, visited, timer, graph);
            low[start] = min(low[start], low[x]);
            if(low[x] >= low[start] && parent != -1){
                articulationPoint.push_back(start);
            }
            child++;
        }
        else{
            low[start] = min(low[start], tin[x]);
        }
    }
    if(parent == -1 && child > 1){
        articulationPoint.push_back(start);
    }
}


void articulation(vector<vector<int> > graph, int n){
    bool visited[n];
    int tin[n];
    int low[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
        tin[i] = -1;
        low[i] = -1;
    }
    vector<int> articulationPoint;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i, -1, articulationPoint, tin, low, visited, 1, graph);
        }
    }
}

int main(){
    cout << "working\n";
    vector<int> x;
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    for(int i : x){
        cout << i << endl;
    }
}
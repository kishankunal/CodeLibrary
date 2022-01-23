//https://www.interviewbit.com/problems/commutable-islands/discussion/p/simple-kruskal-algorithm-c/49999/1057

#include<bits/stdc++.h>
using namespace std;

//minimum spanning tree
struct node{
    int u;
    int v;
    int wt;
    
};
bool comp(node &a, node &b){
    return a.wt < b.wt;
}
int getParent(int u, int *parent){
    if(parent[u] == u){
        return u;
    }
    return parent[u] = getParent(parent[u], parent); //path compression
}
int kruskal(node graph[], int n, int e){
    int parent[n+1];
    for(int i = 0; i<=n; i++){
        parent[i] = i;
    }
    int cost = 0;
    int count=0;
    for(int i = 0; i < e; i++){
        if(count == n-1){
            break;
        }
        node edge = graph[i];
        if(getParent(edge.u, parent) != getParent(edge.v, parent)){
            cost+=edge.wt;
            parent[edge.u] = edge.v;
            count++;
        }
    }
    
    return cost;
}
int solve(int n, vector<vector<int> > &b) {
    int e = b.size();
    struct node graph[e];
    for(int i = 0; i<e; i++){
        graph[i].u = b[i][0];
        graph[i].v = b[i][1];
        graph[i].wt = b[i][2];
    }
    sort(graph, graph+e, comp);
    return kruskal(graph, n, e);
}

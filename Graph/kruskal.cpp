#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
bool comp(node *a, node *b){
    return a->wt<b->wt;
}

int getParent(int u, int *parent){
    if(parent[u] == u){
        return u;
    }
    return parent[u] = getParent(parent[u], parent);
}
vector<pair<int,int>> kruskal(node edges[], int n, int e){
    sort(edges, edges+e, comp);
    int parent[n];
    vector<pair<int, int>> mst;
    for(int i = 0; i<n; i++){
        parent[i] = i;
    }
    int count = 0;
    int cost = 0;
    for(int i = 0; i<e; i++){
        if(count == n-1){
            break;
        }
        node edge= edges[i];
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;
        if(getParent(u, parent) != getParent(v, parent)){
            mst.push_back({u, v});
            count++;
            parent[u] = v;
            cost += wt;
        }
    }
    return mst;
}
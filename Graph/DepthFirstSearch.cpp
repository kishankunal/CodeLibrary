//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/?track=DSASP-Graph&batchId=183
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], bool *visited, int s, vector<int> &res)
{
    visited[s] = true;
    res.push_back(s);
    for (int x : adj[s])
    {
        if (!visited[x])
        {
            dfs(adj, visited, x, res);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    vector<int> res;
    dfs(adj, visited, 0, res);
    return res;
}
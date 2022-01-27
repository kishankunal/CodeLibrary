//https://practice.geeksforgeeks.org/problems/mother-vertex/1/?track=DSASP-Graph&batchId=183
#include <bits/stdc++.h>
using namespace std;

bool isAllVisited(bool visited[], int v)
{
    bool flag = true;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void recDFS(int s, vector<int> adj[], bool visited[])
{
    visited[s] = true;
    for (int x : adj[s])
    {
        if (!visited[x])
        {
            recDFS(x, adj, visited);
        }
    }
}
int findMotherVertex(int V, vector<int> adj[])
{
    bool visited[V];
    fill(visited, visited + V, false);
    int v = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            recDFS(i, adj, visited);
            v = i;
        }
    }
    fill(visited, visited + V, false);
    recDFS(v, adj, visited);
    if (isAllVisited(visited, V))
    {
        return v;
    }
    return -1;
}
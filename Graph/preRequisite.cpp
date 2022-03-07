
#include <bits/stdc++.h>
using namespace std;
bool dfs(int start, vector<int> adj[], bool *visited, bool *rec)
{
    visited[start] = true;
    rec[start] = true;
    for (auto x : adj[start])
    {
        if (!visited[x])
        {
            if (dfs(x, adj, visited, rec))
            {
                return true;
            }
        }
        else
        {
            if (rec[x])
            {

                return true;
            }
        }
    }
    rec[start] = false;
    return false;
}
bool isPossible(int n, vector<pair<int, int>> &graph)
{
    vector<int> adj[n];
    for (int i = 0; i < graph.size(); i++)
    {
        adj[graph[i].second].push_back(graph[i].first);
    }
    bool visited[n];
    bool recstk[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        recstk[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, recstk))
            {
                return false;
            }
        }
    }
    return true;
}
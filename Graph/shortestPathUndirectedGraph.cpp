#include <bits/stdc++.h>
using namespace std;
//unweighted graph
void bfs(int *dist, vector<vector<int>> &graph, int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto i : graph[node])
        {
            if (dist[i] > dist[node] + 1)
            {
                q.push(i);
                dist[i] = dist[node] + 1;
            }
        }
    }
}
int shortestPathLength(vector<vector<int>> &graph)
{
    int n = graph.size();
    int *dist = new int(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    bfs(dist, graph, 0);
    return 0;
}
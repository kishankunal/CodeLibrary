//https://classroom.codingninjas.com/app/classroom/me/930/content/13833/offering/119825/problem/1725

#include <bits/stdc++.h>
using namespace std;

//find shortest path from source node to all the reamaining node in an undirected graph

void djks(vector<pair<int, int>> graph[], int n)
{
    int dist[n]; // it will be intmax
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //it will be storing pair dist, node
    int source = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int prev = pq.top().second;
        for (auto node : graph[prev])
        {
            int next = node.first;
            int val = node.second;
            if (dist[next] > dist[prev] + val)
            {
                dist[next] = dist[prev] + val;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "distance from sources are : ";
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << endl;
    }
}

//
int getMinVertex(int *dist, bool *visited, int n)
{
    int min = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min == -1 || dist[min] > dist[i]))
        {
            min = i;
        }
    }
    return min;
}
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> res;
    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            graph[i][adj[i][j][0]] = adj[i][j][1];
            graph[adj[i][j][0]][i] = adj[i][j][1];
        }
    }
    bool visited[V];
    int *dist = new int[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int minVertex = getMinVertex(dist, visited, V);
        visited[minVertex] = true;
        for (int j = 0; j < V; j++)
        {
            if ((graph[minVertex][j] != 0) && (!visited[j]) && (dist[j] > dist[minVertex] + graph[minVertex][j]))
            {
                dist[j] = dist[minVertex] + graph[minVertex][j];
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        res.push_back(dist[i]);
    }
    return res;
}

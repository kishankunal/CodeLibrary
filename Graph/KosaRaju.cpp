#include <bits/stdc++.h>
using namespace std;

//it is used to find strongly connected components
//step - 1 find topological sort
//transpose the graph
// find dfs based on topo sort
void dfsTopo(int start, bool *visited, stack<int> &stk, vector<int> graph[])
{
    visited[start] = true;
    for (auto a : graph[start])
    {
        if (!visited)
        {
            dfsTopo(a, visited, stk, graph);
        }
    }
    stk.push(start);
}

void dfs(int start, vector<int> graph[], bool *visited, vector<int> &ans)
{
    visited[start] = true;
    ans.push_back(start);
    for(auto a : graph[start]){
        if(!visited[a]){
            dfs(a, graph, visited, ans);
        }
    }
}

vector<vector<int>> kosaRaju(vector<int> graph[], int n)
{
    stack<int> topo;
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        dfsTopo(i, visited, topo, graph);
    }

    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        for (auto a : graph[i])
        {
            transpose[a].push_back(i);
        }
    }
    vector<vector<int>> scc;
    while (!topo.empty())
    {
        int top = topo.top();
        topo.pop();
        if (!visited[top])
        {
            vector<int> ans;
            dfs(top, transpose, visited, ans);
            scc.push_back(ans);
        }
    }
    return scc;
}
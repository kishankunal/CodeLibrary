//https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1/?track=DSASP-Graph&batchId=183
#include <bits/stdc++.h>
using namespace std;

void countPath(vector<int> adj[], int st, int des, int &count)
{
    if (st == des)
    {
        count++;
    }
    for (int x : adj[st])
    {
        countPath(adj, x, des, count);
    }
}
int countPaths(int V, vector<int> adj[], int source, int des)
{

    int count = 0;
    countPath(adj, source, des, count);
    return count;
}
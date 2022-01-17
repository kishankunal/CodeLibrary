//https://classroom.codingninjas.com/app/classroom/me/930/content/13833/offering/119825/problem/1725

#include<bits/stdc++.h>
using namespace std;


//find shortest path from source node to all the reamaining node in an undirected graph

void djks(vector<pair<int,int> > graph[], int n){
    bool visited[n];
    int dist[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
        dist[i] =INT_MAX;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
    //it will be storing pair dist, node
    int source = 0;
    pq.push({0,source});
    while(!pq.empty()){
        int len = pq.top().first;
        int prev = pq.top().second;
        for(auto node : graph[prev]){
            int next = node.first;
            int val = node.second;
            if(dist[next] > dist[prev] + val){
                dist[next] = dist[prev] + val;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "distance from sources are : ";
    for(itn i = 1; i<=n; i++){
        cout << dist[i] << endl;
    }
}

//https://www.interviewbit.com/problems/valid-path/
#include<bits/stdc++.h>
using namespace std;

int r[8]={-1,-1,0,1,1,1,0,-1};
int c[8]={0,1,1,1,0,-1,-1,-1};
bool inCircle(vector<int> &xc, vector<int> &yc, int r, int i, int j){
    for(int k = 0; k<xc.size(); k++){
        if((((xc[k] - i) * (xc[k] - i)) + ((yc[k] -j) * (yc[k] - j))) <= r*r){
            return true;
        }
    }
    return false;
}
string solve(int x, int y, int n, int rad, vector<int> &E, vector<int> &F) {
    queue<pair<int, int>> q;
    q.push({0,0});
    vector<vector<int>> vis(105, vector<int>(105, 0));
    vis[0][0] = 1;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k = 0; k<8; k++){
            if(i+r[k]>=0 && i+r[k]<=x && j+c[k]>=0 && j+c[k]<=y && !vis[i+r[k]][j+c[k]] && !inCircle(E,F,rad,i+r[k],j+c[k])){
                vis[i+r[k]][j+c[k]]=1;
                if(i+r[k]==x and j+c[k]==y){
                    return "YES";
                }
                q.push({i+r[k],j+c[k]});
            }
        }
    }
    return "NO";
}

#include<bits/stdc++.h>
using namespace std;

int x[] = {-2,-2,2,2,-1,-1,1,1};
int y[] = {1,-1,1,-1,-2,2,-2,2};

int knight(int n, int m, int C, int D, int E, int F) {
    queue<array<int, 3>> q;
    q.push({C, D, 0});
    int visited[n+1][m+1];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            visited[i][j] = 0;
        }
    }
    visited[C][D] = 1;
    while(!q.empty()){
        array<int, 3> z = q.front();
        q.pop();
        int srcX1 = z[0];
        int srcY1 = z[1];
        int d = z[2];
        if(srcX1 == E && srcY1 == F){
            return d;
        }
        for(int i = 0; i<8; i++){
            int srcX = srcX1 + x[i];
            int srcY = srcY1  + y[i];
           if(srcX > 0 && srcX <= n && srcY > 0 && srcY <= m && visited[srcX][srcY]==0){
               visited[srcX][srcY] = 1;
               q.push({srcX, srcY, d+1});
            }
        }
    }
    return -1;
}

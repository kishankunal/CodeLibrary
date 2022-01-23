//https://www.interviewbit.com/old/problems/path-in-matrix/
#include<bits/stdc++.h>
using namespace std;

int r[] = {0, -1, 0, 1};
int c[] = {-1, 0, 1, 0};
bool dfs(int x, int y, vector<vector<int> > &A, int n, int m){
    if(x < 0  || x >= n || y < 0 || y >= m  || A[x][y] == 0){
        return false;
    }
    if(A[x][y] == 2){
        return true;
    }
    A[x][y] = 0;
    return dfs(x + r[0], y+ c[0], A, n, m) || dfs(x + r[1], y+ c[1], A, n, m)
    || dfs(x + r[2], y+ c[2], A, n, m) ||dfs(x + r[3], y+ c[3], A, n, m);
}
int checkPath(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    for(int i = 0; i<n;i++){
        
        for(int j = 0; j<m; j++){
            if(A[i][j] == 1){
                if(dfs(i, j, A, n, m)){
                    return 1;
                }
                return 0;
            }
        }
    }
    return 0;
}

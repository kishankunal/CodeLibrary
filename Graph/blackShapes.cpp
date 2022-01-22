//https://www.interviewbit.com/problems/black-shapes/discussion/p/easy-dfs-solution-c/74473/944
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<string> &a, int x, int y, int n, int m){
    if(x < 0 || x >= n || y<0 || y >= m){
        return;
    }
    if(a[x][y] != 'X'){
        return;
    }
    a[x][y] = '0';
    dfs(a, x+1, y, n, m);
    dfs(a, x, y+1, n, m);
    dfs(a, x-1, y, n, m);
    dfs(a, x, y-1, n, m);
}

int black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();

    int maxm = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]== 'X'){
                dfs(A, i, j, n, m);
                maxm++;
            }
        }
    }
    return maxm;
}

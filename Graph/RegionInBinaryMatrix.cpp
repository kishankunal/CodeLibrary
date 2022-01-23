//https://www.interviewbit.com/old/problems/region-in-binarymatrix/
#include<bits/stdc++.h>
using namespace std;


int r[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int c[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dfs(vector<vector<int> > &A, int i, int j, int n, int m){
    if(i<0 || i>=n ||j<0||j>=m || A[i][j]==0){
        return 0;
    }
    A[i][j] = 0;
    int temp = 0;
    for(int k = 0; k<8; k++){
        int x = i+r[k];
        int y = j+c[k];
        temp += dfs(A, x, y, n, m);
    }
    return temp + 1;
}
int solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int maxm = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j] == 1){
                int temp = dfs(A, i, j, n, m);
                maxm = max(maxm, temp);
            }
        }
    }
    return maxm;
}
//https://www.interviewbit.com/problems/word-search-board/

#include<bits/stdc++.h>
using namespace std;

// possible directions to dfs into
int dx[]= { 1, 0, -1, 0 };
int dy[]= { 0, 1, 0, -1 };

int dfs(int x, int y, vector<string> &g, int m, int n, int id, string &s){
    if(id>= s.length()) return true; // if id is greater than or equal to string length, string is found
    if(g[x][y] != s[id]) return false;  // if current char in the matrix doesn't match the string at index id no need to dfs further
    
    int flag= 0;
    
    for(int i= 0; i< 4; ++i){
        int xdx= x + dx[i];
        int ydy= y + dy[i];
        
        if(xdx >= m || xdx < 0 || ydy < 0 || ydy >= n) continue;
        
        flag= dfs(xdx, ydy, g, m, n, id+1, s); // dfs for each possible direction
        
        if(flag) return flag; // if string is found return true;
    }
    
    return flag;
}

int exist(vector<string> &A, string B) {
    int m= A.size();
    int n= m ? A[0].size() : 0;
    
    if(m== 0 || n== 0) return B.length() == 0 ? 1 : 0;
    
    for(int i= 0; i< m; ++i){
        for(int j= 0; j< n; ++j){
            int flag= dfs(i, j, A, m, n, 0, B);
            
            if(flag) return flag;
        }
    }
    
    return 0;
}
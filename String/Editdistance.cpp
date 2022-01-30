#include<bits/stdc++.h>
using namespace std;
int minimum(int x, int y){
    if(x >= y){
        return y;
    }
    return x;
}

int editDistance(string str1, string str2, int n, int m, int **arr){
    if(arr[n][m] != -1){
        return arr[n][m];
    }
    if(m == 0){
        return arr[m][n] = n;
    }
    if(n == 0){
        return arr[m][n] = m;
    }

    if(str1[n-1] = str2[m-1]){
        return arr[m][n] = editDistance(str1, str2, n-1, m-1, arr);
    }
    return arr[m][n] = 1 + minimum(editDistance(str1, str2, n-1, m-1, arr), minimum(editDistance(str1, str2, n-1, m, arr), editDistance(str1, str2, n, m-1, arr)));
}
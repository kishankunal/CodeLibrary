
#include<bits/stdc++.h>
using namespace std;

int lcs(string str1, int n, string str2, int m, int **arr){
    if(arr[m][n] != -1){
        return arr[m][n];
    }
    if(m == 0 || n == 0){
        return arr[m][n] = 0;
    }
    if (str1[n-1] == str2[m-1])
    {
        return arr[m][n] = 1 + (lcs(str1, n-1, str2, m-1, arr));
    }
    return arr[m][n] = max(lcs(str1, n-1, str2, m, arr),  lcs(str1, n, str2, m-1, arr));
}
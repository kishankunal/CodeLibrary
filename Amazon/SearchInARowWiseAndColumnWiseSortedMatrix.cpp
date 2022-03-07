//https://www.codingninjas.com/codestudio/problems/search-in-a-row-wise-and-column-wise-sorted-matrix_839811
#include<bits/stdc++.h>
using namespace std;

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m-1;
    while(i < n && j>=0){
        if(matrix[i][j] == x){
            return {i, j};
        }
        else if(matrix[i][j] < x){
            i++;
        }
        else{
            j--;
        }
    }
    return {-1, -1};
}
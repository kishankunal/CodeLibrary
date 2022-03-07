//https://leetcode.com/problems/search-a-2d-matrix/submissions/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool bin(vector<vector<int>>& matrix, int target, int col, int big, int end){
        while(big <= end){
            int mid = (big + end) >> 1;
            int mid_el = matrix[mid/col][mid%col];
            if(mid_el == target){
                return true;
            }
            else if(mid_el > target ){
                end = mid - 1;
            }
            else{
                big = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return bin(matrix, target, matrix[0].size(), 0, matrix.size() * matrix[0].size() - 1);
    }
};
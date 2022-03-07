//https://leetcode.com/problems/minimum-size-subarray-sum/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int leftPos = 0;
        int len = INT_MAX;
        int sum = 0;
        bool flag = false;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            if(sum >= target){
                flag = true;
                while(sum >= target){
                    sum -= arr[leftPos++];
                }
                len = min(len,i - leftPos + 2);
            }
        }
        return flag ? len : 0;
    }
};
//https://leetcode.com/problems/find-peak-element/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low,high;
        low=0,high=nums.size()-1;
        if(n==1) return 0;
        while(low<=high){
            int mid=(low+high) >> 1;
            if(mid==0){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                else{
                    low=mid+1;
                }
            }
            else if(mid==n-1){
                if(nums[mid]>nums[mid-1]){
                    return mid;
                } 
                else{
                   high=mid-1; 
                }
            }
            else{
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                } 
                else if(nums[mid-1]>nums[mid]){
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while(low < high)
        {
            int mid = (low + high) >> 1;  
            if(arr[mid] == arr[low] && arr[mid] == arr[high])
            {
                low++;  
                high--;
            }
            else if(arr[mid] > arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return arr[low];
    }
};
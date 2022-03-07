//https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
#include<bits/stdc++.h>
using namespace std;

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
	

	int sum = INT_MIN;
	int temp = 0;
	for(int i = 0; i<n; i++){
		temp = temp + A[i];
		sum = std::max(temp, sum);
       
		if((temp < 0)){
			temp = 0;
		}
	}
	return sum;
}
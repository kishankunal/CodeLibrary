//https://www.interviewbit.com/problems/spiral-order-matrix-i/
#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> ans;
	int n = A.size();
	int m = A[0].size();
	int left = 0;
	int right = m-1;
	int top = 0;
	int down = n-1;
	while(top<=down && left <= right){
		for(int i = left; i<=right; i++){
			ans.push_back(A[top][i]);
		}
		top++;
		for(int i = top; i <=down; i++){
			ans.push_back(A[i][right]);
		}
		right--;
		if(top<=down){
			for(int i = right; i>=left; i--){
				ans.push_back(A[down][i]);
			}
			down--;
		}
		if(left<=right){
			for(int i = down; i>=top; i--){
				ans.push_back(A[i][left]);
			}
			left++;
		}
	}
	return ans;
	
}
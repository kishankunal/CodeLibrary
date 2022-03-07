//https://www.interviewbit.com/problems/first-missing-integer/
#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {

    sort(A.begin(), A.end());
    int temp = 1;
    for(int i = 0; i<A.size(); i++){
        if(A[i] >0 && A[i]== temp){
            temp++;
        }
        else{
            return temp;
        }
    }
    return temp;
}
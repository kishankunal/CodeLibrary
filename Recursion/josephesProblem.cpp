//https://practice.geeksforgeeks.org/problems/josephus-problem/0/?track=DSASP-Recursion&batchId=183
#include<bits/stdc++.h>
using namespace std;

int jos(int n, int k){
    if(n==0){
        return 0;
    }
    return  (jos(n-1,k)+k)%n;
}

int josephus(int n, int k)
{
   return jos(n,k) + 1;
}
 
 
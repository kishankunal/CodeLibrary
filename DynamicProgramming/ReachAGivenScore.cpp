//https://practice.geeksforgeeks.org/problems/reach-a-given-score1418/0/?track=DSASP-DP&batchId=183
#include<bits/stdc++.h>
using namespace std;

ll count(ll n) 
{
    ll table[n+1];
    for(int i = 0; i<=n; i++){
        table[i] = 0;
    }
    table[0] = 1;
    for(int i = 3; i<=n; i++){
        table[i] += table[i-3];
    }
    for(int i = 5; i<=n; i++){
        table[i] += table[i-5];
    }
    for(int i = 10; i<=n; i++){
        table[i] += table[i-10];
    }
    return table[n];
}
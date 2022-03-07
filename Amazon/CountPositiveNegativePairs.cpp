//https://www.codingninjas.com/codestudio/problems/count-positive-negative-pairs_630513
#include<bits/stdc++.h>
using namespace std;

long long countPositiveNegativePairs(int arr[], int n)
{
    unordered_map<int, long long int> data;
    long long int count = 0;
    for(int i = 0; i<n; i++){
        if(data[-1*arr[i]] > 0){
            count+= data[-1*arr[i]];
        }
        data[arr[i]]++;
    }
    return count;
}
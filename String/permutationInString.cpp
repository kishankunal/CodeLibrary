//https://leetcode.com/problems/permutation-in-string/
#include<bits/stdc++.h>
using namespace std;

 bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        unordered_map<char, int> freq1, freq2;
        for(int i = 0; i<n; i++){
            freq1[s1[i]]++;
        }
        freq2 = freq1;
        for(int i = 0; i<m-n+1; i++){
            for(int j = i; j<i+n; j++){
                freq2[s2[j]]--;
            }
            bool flag = true;
            for(auto x : freq2){
                if(x.second!=0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
            freq2 = freq1;
        }
        return false;
    }
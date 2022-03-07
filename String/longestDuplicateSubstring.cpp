//https://leetcode.com/problems/longest-duplicate-substring/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        unordered_map<char, vector<int>> mp;
        int n = s.size();
        for(int i = 0; i<n; i++){
            mp[s[i]].push_back(i);
        }
        int max = 0;
        int index = -1;
        
        for(int i = 0; i<n; i++){
            char f = s[i];
            
            for(int x : mp[f]){
                if(x == i){
                    continue;
                }
                int j = 0;
                while(i + j < n && x + j < n && s[i+j] == s[x+j]){
                    j++;
                }
                if( j > max){
                    max = j;
                    index = i;
                }
                
            }
        }
        if(max == 0){
            return 0;
        }
        return s.substr(index, max);
    }
};
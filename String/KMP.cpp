#include<bits/stdc++.h>
using namespace std;

int* computeLps(string p){
    int *lps = new int[p.length()];
    int j = 0;
    lps[0] = 0;
    int i = 1;
    while(i < p.length()){
        if(p[j] == p[i]){
            lps[i++] = ++j;
        }
        else{
            if(j!=0){
                j = lps[--j];
            }else{
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

int KMP(string t , string p){
    int *lps = computeLps(p);
    int m = t.length();
    int n = p.length();
    int i = 0, j = 0;
    while(i < m && j < n){
        if(t[i] == p[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[--j];
            }else{
                i++;
            }
        }
    }
    if(j == n){
        return i - n;
    }
    return -1;
}
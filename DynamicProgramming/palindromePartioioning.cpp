
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return t==s;
}

int part(string s, int i, int j){
    if(ispalindrome(s)){
        return 0;
    }
    int res = INT_MAX;

    for(int k = i; k<j; k++){
        res = min(res, 1 + part(s, i, k) + part(s, k, j));
    }
    return res;
}
//https://www.codingninjas.com/codestudio/problems/print-permutations-string_758958?leftPanelTab=2
#include<bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r, vector<string> &ans)
{
    if (l == r)
        ans.push_back(a);
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r, ans);
            swap(a[l], a[i]);
        }
    }
}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    permute(s, 0, s.size()-1, ans);
    return ans;
    
}
INT64_MIN
#include <bits/stdc++.h>
using namespace std;

string extend(string s, int l, int r)
{
    int len = 0;
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        if(r==l){
            len++;
        }
        else{
            len+=2;
        }
        l--;
        r++;
    }
    return s.substr(l + 1, len);
}

string Solution::longestPalindrome(string s)
{
    if (s.size() < 2)
        return s;
    string max = "";
    for (int i = 0; i < s.size(); i++)
    {
        string s1 = extend(s, i, i);
        string s2 = extend(s, i, i + 1);
        if (s1.size() > max.size())
            max = s1;
        if (s2.size() > max.size())
            max = s2;
    }
    return max;
}

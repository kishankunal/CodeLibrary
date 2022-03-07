//https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_758894?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int lengthOfLongestSubstring(string &str)
{
    int n = str.size();

    int res = 0;
    vector<int> lastIndex(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, lastIndex[str[j]] + 1);
        res = max(res, j - i + 1);
        lastIndex[str[j]] = j;
    }
    return res;
}
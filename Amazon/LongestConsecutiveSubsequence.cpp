//https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_759408?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int len = 1;
    int temp = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            temp++;
        }
        else if (arr[i] == arr[i - 1])
        {
            continue;
        }
        else
        {
            temp = 1;
        }
        len = max(len, temp);
    }
    return len;
}
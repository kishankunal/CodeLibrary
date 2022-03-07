//https://www.codingninjas.com/codestudio/problems/3-sum-smaller_3161884?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int threeSumSmaller(int n, vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int x = arr[i] + arr[j] + arr[k];
            if (x < target)
            {
                ans += k - j;
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

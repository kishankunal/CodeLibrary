//https://www.codingninjas.com/codestudio/problems/maximum-sum-rectangle_875115?leftPanelTab=1
#include <bits/stdc++.h>
using namespace std;

int kadane(int *arr, int n)
{
    int sum = INT_MIN;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        sum = max(sum, temp);
        if (temp < 0)
        {
            temp = 0;
        }
    }
    return sum;
}
int maxSumRectangle(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int temp[n];
    int maxSum = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j] = 0;
        }
        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp[k] += arr[k][j];
            }
            int sum = kadane(temp, n);
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
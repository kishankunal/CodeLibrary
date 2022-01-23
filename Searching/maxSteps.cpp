//https://practice.geeksforgeeks.org/problems/roof-top-1587115621/0/?track=DSASP-Searching&batchId=183
#include <bits/stdc++.h>
using namespace std;

int maxStep(int arr[], int n)
{
    int steps = 0;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            count++;
        }
        else
        {
            count = 0;
        }
        steps = max(count, steps);
    }
    return steps;
}
//https://practice.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/0/?track=DSASP-Sorting&batchId=183
#include <bits/stdc++.h>
using namespace std;

void sortABS(int arr[], int n, int k)
{
    stable_sort(arr, arr + n, [k](int a, int b)
                { return abs(a - k) < abs(b - k); });
}
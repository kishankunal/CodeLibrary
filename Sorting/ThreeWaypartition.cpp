//https://practice.geeksforgeeks.org/problems/three-way-partitioning/0/?track=DSASP-Sorting&batchId=183
#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int> &arr, int a, int b)
{
    int start = -1;
    int end = arr.size();
    for (int i = 0; i < end;)
    {
        if (arr[i] < a)
        {
            swap(arr[i++], arr[++start]);
        }
        else if (arr[i] > b)
        {
            swap(arr[i], arr[--end]);
        }
        else
        {
            i++;
        }
    }
}
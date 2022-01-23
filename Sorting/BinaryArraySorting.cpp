//https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1/?track=DSASP-Sorting&batchId=183
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void binSort(int arr[], int n)
{
    int low = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(&arr[++low], &arr[i]);
        }
    }
}
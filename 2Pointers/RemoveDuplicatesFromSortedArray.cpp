//https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int n = arr.size();
    int i = 1;
    int j = 0;
    while (i < n)
    {
        if (arr[i] == arr[j])
        {
            i++;
        }
        else
        {
            if (i == j + 1)
            {
                i++;
                j++;
            }
            else
            {
                swap(arr[i++], arr[++j]);
            }
        }
    }
    return j + 1;
}

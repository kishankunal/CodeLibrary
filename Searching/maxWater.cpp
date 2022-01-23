#include <bits/stdc++.h>
using namespace std;

int maxWater(int height[], int n)
{
    int water = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        water = max(water, min(height[i], height[j]) * (j - i - 1));
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return water;
}

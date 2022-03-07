//https://www.codingninjas.com/codestudio/problems/largest-rectangle-in-a-histogram_1058184?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;
int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    int leftSmaller[n];
    int rightSmaller[n];
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            leftSmaller[i] = 0;
        }
        else
        {
            leftSmaller[i] = stk.top() + 1;
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        stk.pop();
    }
    int area = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            rightSmaller[i] = n - 1;
        }
        else
        {
            rightSmaller[i] = stk.top() - 1;
        }
        area = max(area, (rightSmaller[i] - leftSmaller[i] + 1) * heights[i]);
        stk.push(i);
    }
    return area;
}
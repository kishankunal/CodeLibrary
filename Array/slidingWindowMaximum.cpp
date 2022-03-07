class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        list<int> stk;
        for (int i = 0; i < k; i++)
        {

            while (!stk.empty() && arr[stk.back()] <= arr[i])
            {
                stk.pop_back();
            }
            stk.push_back(i);
        }
        for (int i = k; i < n; i++)
        {
            ans.push_back(arr[stk.front()]);
            while (!stk.empty() && stk.front() <= i - k)
            {
                stk.pop_front();
            }
            while (!stk.empty() && arr[stk.back()] <= arr[i])
            {
                stk.pop_back();
            }

            stk.push_back(i);
        }
        if (!stk.empty())
        {
            ans.push_back(arr[stk.front()]);
        }

        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    double median;
    
    priority_queue<int> max; 
	priority_queue<int, vector<int>, greater<int> > min;
    void insertHeap(int &x)
    {
    	if (max.empty()) 
    		max.push(x);
    	else if (x > max.top()) 
    		min.push(x);
    	else
    		max.push(x);
    		
    	balanceHeaps();
    }
    int abs(int x){
        if(x < 0){
            return -1*x;
        }
        return x;
    }
    void balanceHeaps()
    {
    	if (abs(max.size() - min.size()) > 1) 
    	{
    		if (max.size() > min.size())
    		{
    			min.push(max.top());
    			max.pop();
    		}
    		else
    		{
    			max.push(min.top());
    			min.pop();
    		}
    	}
    }
    
    double getMedian()
    {
   	if ((max.size() + min.size()) % 2 == 0)
    	{
    		median = (max.top() + min.top());
    		median /= 2;
    	}
    	else 
    	{
    		if (min.empty())
    			median = max.top();
    		else if (min.size() < max.size())
    			median = max.top();
    		else
    			median = min.top();
    	}
    	
    	return median;
    }
};
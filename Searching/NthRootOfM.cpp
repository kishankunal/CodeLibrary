#include<bits/stdc++.h>
using namespace std;

public class Solution {
    static double multiple(int x, int n){
        double ans = 1.0;
        for(int i = 0; i<n; i++){
            ans *= x;
        }
        return ans;
    }
    public: static double findNthRootOfM(int n, long m) {
    	double first = 1;
        double last = m;
        double eps = 1e-6;
        double ans = 0;
        while((last- first) > eps){
            double mid = (first + last)/ 2.0;
            if(multiple(mid, n) <= m){
                ans = mid;
                first = mid;
            }
            else{
                last = mid;
            }
        }
        return ans;
    }
};
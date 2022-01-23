#include <bits/stdc++.h>
using namespace std;

int counter=2;


bool isLucky(int n) {
    if(counter<=n) {
        
        if(n%counter==0)
            return false;
        n = n-n/counter;
        counter++;
        isLucky(n);
    }
    else
        return true;
}
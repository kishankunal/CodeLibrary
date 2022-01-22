//https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
#include <bits/stdc++.h>
using namespace std;

string multiple(int a) {
   if(a==1){
       return "1";
   }
   queue<int> q;
   q.push(1);
   vector<char> v(a,'2');
   vector<int> parent(a, -1);
   v[1] = '1';
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(front == 0){
            int rem = 0;
            string s = "";
            while(rem!=1){
                s+=v[rem];
                rem = parent[rem];
            }
            s+="1";
            reverse(s.begin(), s.end());
            return s;
        }
        else{
            int b = (front*10)%a;
            int c = (front*10+1)%a;
            if(v[b]=='2'){
                parent[b] = front;
                v[b] = '0';
                q.push(b);
            }
            if(v[c]=='2'){
                v[c] = '1';
                parent[c] = front;
                q.push(c);
            }
        }
    }
    
}

#include<bits/stdc++.h>
using namespace std;

//using two queues
void push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue s = q1;
    q1 = q2;
    q2 = s;
}

//using 1 queue
void push(int x){
    q1.push(x);
    int n = q1.size();
    for(int i = 0; i<n-1; i++){
        q1.push(q1.front());
        q1.pop();
    }
}

int top(){
    return q1.front();
}

void pop(){
    q1.pop();
}


#include<bits/stdc++.h>
using namespace std;

void push(int x){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

int top(){
    return s1.top();
}

void pop(){
    s1.pop();
}



//optimised algorithm


void push(int x){
    input1.push(x);
}

void pop(){
    if(output1.size() == 0){
        while(!input1.empty()){
            output1.push(input1.top());
            input1.pop();
        }
    }
    output1.pop();
}

int top(){
    if(output1.size() == 0){
        while(!input1.empty()){
            output1.push(input1.top());
            input1.pop();
        }
    }
    return output1.top();
}
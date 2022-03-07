#include<bits/stdc++.h>
using namespace std;


string multiple(int a) {
    if(a == 1){
        return "1";
    }
    queue<int> rem;
    rem.push(1);
    vector<string> data(a+1, "-1");
    vector<int> parent(a+1, -1);
    data[1] = "1";
    while(!rem.empty()){
        int x = rem.front();
        rem.pop();
        if(x == 0){
            string s = "";
            while(x!=1){
                s+= data[x];
                x = parent[x];
            }
            s += "1";
            reverse(s.begin(), s.end());
            return s;
        }
        else{
            int p = (x*10)%a;
            int b = (x*10 + 1) %a;
            if(data[p] == "-1"){
                parent[p] = x;
                rem.push(p);
                data[p] = "0";
            }
            if(data[b] == "-1"){
                parent[b] = x;
                data[b] = "1";
                rem.push(b);
            }
        }
       
    }
    return "";
}


int main(){
    cout << multiple(55) << endl;
}
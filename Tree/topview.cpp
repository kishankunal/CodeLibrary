#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};


vector<int> topView(treeNode *root){
    vector<int> res;
    map<int, int> mp;
    if(!root){
        return res;
    }
    queue<pair<treeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        treeNode *top = q.front().first;
        int x = q.front().second;
        if(mp.find(x) == mp.end()){
            mp[x] = top->data;
        }
        if(top->left){
            q.push({top->left, x-1});
        }
        if(top->right){
            q.push({top->right, x+1});
        }
    }
    for(pair<int, int> x : mp){
        res.push_back(x.second);
    }
    return res;
}
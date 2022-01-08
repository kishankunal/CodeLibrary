#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

vector<int> bottomView(treeNode *root){
    map<int, int> mp;
    vector<int> res;
    queue<pair<treeNode* , int>> q;
    if(!root){
        return res;
    }
    q.push({root, 0});
    while(!q.empty()){
        treeNode *top = q.front().first;
        int x = q.front().second;
        mp[x] = top->data;
        if(top->left){
            q.push({top->left, x-1});
        }
        if(top->right){
            q.push({top->right, x+1});
        }
    }
    for(auto a : mp){
        res.push_back(a.second);
    }
    return res;
}
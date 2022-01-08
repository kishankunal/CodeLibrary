#include <bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode *left = NULL;
    treeNode *right = NULL;
    int data = 0;
};

 void inorder(treeNode *root, map<int,map<int, vector<int>>> &mp, int x, int y){
       if(!root){
           return ;
       }
        inorder(root->left, mp, x-1, y+1);
        mp[x][y].push_back(root->data);
        inorder(root->right, mp, x+1, y+1);
    }
    vector<vector<int>> verticalTraversal(treeNode* root) {
        vector<vector<int>> res;
        int x = 0;
        int y = 0;
        map<int,map<int, vector<int>>> data;
        inorder(root, data, x, y);
        for(auto a : data){
            vector<int> xyz;
            for(auto b : a.second){
                sort(b.second.begin(), b.second.end());
                xyz.insert(xyz.end(),b.second.begin(), b.second.end());
            }
            res.push_back(xyz);
        }
        return res;
    }
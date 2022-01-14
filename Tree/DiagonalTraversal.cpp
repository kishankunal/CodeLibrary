//https://www.interviewbit.com/problems/diagonal-traversal/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int val = 0;
};

void preorder(TreeNode *root, map<int, vector<int> > &mp, int x){
     if(!root){
         return;
     }
     mp[x].push_back(root->val);
     preorder(root->left, mp, x+1);
     preorder(root->right, mp, x);
     
 }
vector<int> solve(TreeNode* A) {
    map<int, vector<int>> ans;
    preorder(A, ans, 0);
    vector<int> res;
    for(auto a :ans){
        res.insert(res.end(), a.second.begin(), a.second.end());
    }
    return res;
}

#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int val = 0;
};


void inorder(TreeNode* root, map<int, int> &mp, int level ){
        if(!root){
            return;
        }
        inorder(root->left, mp, level+1);
        mp[level] = root->val;
        inorder(root->right, mp, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        map<int, int> mp;
        inorder(root,mp, 0);
        for(pair<int, int>x : mp){
            res.push_back(x.second);
        }
        return res;
    }
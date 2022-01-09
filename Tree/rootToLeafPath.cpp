#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

bool getpath(TreeNode *root, int a, vector<int> &ans){
    if(!root){
        return false;
    }
    ans.push_back(root->val);
    if(root->val == a){
        return true;
    }
    if(getpath(root->left, a, ans) || getpath(root->right, a, ans)){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> solve(TreeNode *root, int a){
    vector<int> ans;
    getpath(root, a, ans);
    return ans;
}
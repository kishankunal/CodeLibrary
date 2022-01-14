//https://www.interviewbit.com/problems/path-to-given-node/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

bool preorder(TreeNode *root, vector<int> &ans, int B){
    if(!root){
        return false;
    }
    ans.push_back(root->val);
    if(root->val == B){
        return true;
    }
    if(preorder(root->left, ans, B) || preorder(root->right, ans, B)){
        return true;
    }
    ans.pop_back();
    return false;
 }
vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    preorder(A, ans, B);
    return ans;
    
}

//https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
    TreeNode(int x)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = x;
    }
};


void pre(TreeNode *root, vector<vector<int>> &ans, vector<int> &temp, int B, int sum){
     if(!root){
         return;
     }
     sum = sum +  root->val;
     temp.push_back(root->val);
     if(!root->left && !root->right && sum == B){ 
            ans.push_back(temp);  
     }
     pre(root->left, ans, temp, B, sum);
     pre(root->right, ans, temp, B, sum);
     temp.pop_back();
 }
vector<vector<int> > pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    vector<int> a;
    pre(A, ans, a, B, 0);
    return ans;
}
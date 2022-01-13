//https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
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

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    stack<TreeNode *> a;
    stack<TreeNode *> b;
    a.push(root);
    bool flag = false;
    while(!a.empty() || !b.empty()){
        vector<int> temp;
        while(!a.empty()){
            int n = a.size();
                TreeNode *top = a.top();
                temp.push_back(top->val);
                a.pop();
                if(top->left){
                    b.push(top->left);
                }
                if(top->right){
                    b.push(top->right);
                }
        }
        ans.push_back(temp);
        temp.clear();
        while(!b.empty()){
                TreeNode *top = b.top();
                temp.push_back(top->val);
                b.pop();
                if(top->right){
                    a.push(top->right);
                }
                if(top->left){
                    a.push(top->left);
                }
        }
        if(temp.size() > 0){
            ans.push_back(temp);
        temp.clear();
        }
    }
    return ans;
}
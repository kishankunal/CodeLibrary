//https://www.interviewbit.com/problems/nodes-at-distance-k/
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

TreeNode* fillParent(TreeNode *root, map<TreeNode *, TreeNode *> &parent, int B, TreeNode *A){
     queue<TreeNode *> q;
     q.push(root);
     while(!q.empty()){
         TreeNode *top= q.front();
         q.pop();
         if(top->val == B){
             A = top;
         }
         if(top->left){
             q.push(top->left);
             parent[top->left] = top;
         }
         if(top->right){
             q.push(top->right);
             parent[top->right] = top;
         }
     }
     return A;
 }

vector<int> distanceK(TreeNode* root, int B, int C) {
    vector<int> ans;
    TreeNode *A = NULL;
    queue<TreeNode *> q;
    map<TreeNode *, TreeNode *> parent;
    root = fillParent(root, parent, B, A);
    unordered_map<TreeNode *, bool> visited;
    visited[root] = true;
    q.push(root);
    int k = 0;
    while(!q.empty()){
        if(k++ == C){
            break;
        }
        int n = q.size();
        for(int i = 0; i<n; i++){
            TreeNode *top = q.front();
            q.pop();
            if(top->left && !visited[top->left]){
                visited[top->left] = true;
                q.push(top->left);
            }
            if(top->right && !visited[top->right]){
                visited[top->right] = true;
                q.push(top->right);
            }
            if(parent[top] && !visited[parent[top]]){
                visited[parent[top]] = true;
                q.push(parent[top]);
            }
        }
    }
    while(!q.empty()){
        TreeNode *top = q.front();
        q.pop();
        ans.push_back(top->val);
    }
    return ans;
}

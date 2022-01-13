//https://www.interviewbit.com/problems/burn-a-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

TreeNode *fillParent(TreeNode *root, unordered_map<TreeNode* , TreeNode*> &parent, int B){
     TreeNode *A = NULL;
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty()){
         TreeNode *top = q.front();
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
int solve(TreeNode* root, int B) {
    unordered_map<TreeNode *, TreeNode *> parent;
    root = fillParent(root, parent, B);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(root);
    visited[root] = true;
    int k = 0;
    while(!q.empty()){
        int n = q.size();
        bool flag = false;
        for(int i = 0; i<n; i++){
            TreeNode *top = q.front();
            q.pop();
            if(top->left && !visited[top->left]){
                flag = true;
                visited[top->left] = true;
                q.push(top->left);
            }
            if(top->right && !visited[top->right]){
                visited[top->right] = true;
                q.push(top->right);
                flag = true;
            }
            if(parent[top] && !visited[parent[top]]){
                flag = true;
                q.push(parent[top]);
                visited[parent[top]] = true;
            }
        }
        if(flag){
            k++;
        }
    }
    return k;
}
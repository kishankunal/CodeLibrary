#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int val = 0;
};

void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentTrack)
{
    queue<TreeNode *> q;
    q.push(root);
    parentTrack[root] = NULL;
    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();
        if(current->left){
            q.push(current->left);
            parentTrack[current->left] = current;
        }
        if(current->right){
            q.push(current->right);
            parentTrack[current->right] = current;
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parentTrack;
    markParent(root, parentTrack);
    queue<TreeNode *> q;
    unordered_map<TreeNode *, bool> visited;
    int distance = 0;
    q.push(target);
    visited[target] = true;
    while(!q.empty()){
        if(distance++ == k){
            break;
        }
        int n = q.size();
        for(int i = 0; i<n; i++){
            TreeNode *top = q.front();
            q.pop();
            if(top->left && !visited[top->left]){
                q.push(top->left);
                visited[top->left] = true;
            }
            if(top->right && !visited[top->right]){
                q.push(top->right);
                visited[top->right] = true;
            }
            if(parentTrack[top] && !visited[parentTrack[top]]){
                q.push(parentTrack[top]);
                visited[parentTrack[top]] = true;
            }
        }
    }
    vector<int> res;
    while(!q.empty()){
        int top = q.front()->val;
        q.pop();
        res.push_back(top);
    }
    return res;
}
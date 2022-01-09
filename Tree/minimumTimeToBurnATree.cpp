#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};

void makeParent(treeNode *root, unordered_map<treeNode *, treeNode *> &parent){
    queue<treeNode *> q;
    q.push(root);
    while(!q.empty()){
        treeNode *top = q.front();
        if(top->left){
            q.push(top->left);
            parent[top->left] = top;
        }
        if(top->right){
            q.push(top->right);
            parent[top->right] = top;
        }
    }
}

int BurnTree(treeNode *root, treeNode *target){
    unordered_map<treeNode *, treeNode *> parent;
    unordered_map<treeNode *, bool> visited;
    makeParent(root, parent);
    queue<treeNode *> q;
    q.push(target);
    visited[target] = true;
    int time = 0;
    
    while(!q.empty()){
        bool flag = false;
        int n = q.size();
        for(int i = 0; i<n; i++){
            treeNode *top = q.front();
            q.pop();
            if(top->left && !visited[top->left]){
                flag = true;
                visited[top->left] = true;
                q.push(top->left);
            }
            if(top->right && !visited[top->right]){
                flag = true;
                visited[top->right] = true;
                q.push(top->right);
            }
            if(parent[top] && !visited[parent[top]]){
                flag = true;
                visited[parent[top]] = true;
                q.push(parent[top]);
            }
        }
        if(flag){
            time++;
        }
    }
    return time;
}
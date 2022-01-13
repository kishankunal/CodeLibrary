//https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
    int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
void connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    TreeLinkNode * root= A;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i<n; i++){
            TreeLinkNode *top = q.front();
            q.pop();
            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
            if(i == n-1){
                top->next = NULL;
            }
            else{
                top->next = q.front();
            }
        }
    }
    
}
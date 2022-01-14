//https://www.interviewbit.com/problems/covered-uncovered-nodes/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

long coveredNodes(TreeNode* A) {
   long sum1 = 0;
   long sum2 = 0;
   queue<TreeNode *> q;
   q.push(A);
   while(!q.empty()){
       int n = q.size();
       for(int i = 0; i<n; i++){
           TreeNode *top = q.front();
           q.pop();
           if(i == 0 || i == n-1){
               sum1 += top->val;
           }
           else{
               sum2 += top->val;
           }
           if(top->left){
               q.push(top->left);
           }
           if(top->right){
               q.push(top->right);
           }
       }
   }
   return abs(sum1-sum2);
}

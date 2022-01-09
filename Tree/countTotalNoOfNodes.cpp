#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int val = 0;
};
int countNodes(TreeNode* root) {
    if(!root){
        return 0;
    }
    int lh = leftheight(root);
    int rh = rightheight(root);
    if(lh==rh){
        return (1<<lh) -1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int leftheight(TreeNode *root){
    if(!root){
        return 0;
    }
    return 1 + leftheight(root->left);
}
int rightheight(TreeNode *root){
    if(!root){
        return 0;
    }
    return 1 + rightheight(root->right);
}
int main(){

}
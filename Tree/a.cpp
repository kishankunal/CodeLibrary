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
TreeNode *build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &mp){
    if(is > ie  || ps > pe){
        return NULL;
    }
    TreeNode *root= new TreeNode(preorder[ps++]);
    int index = mp[root->val];
    int leftNode = index-is;
    root->left = build(preorder, ps, ps+leftNode, inorder, is, index-1, mp);
    root->right = build(preorder, ps+leftNode+1, pe, inorder, index+1, ie, mp);
    return root;
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> mp;
    for(int i = 0; i<B.size(); i++){
        mp[B[i]] = i;
    }
    return build(A, 0, A.size()-1, B, 0, B.size()-1, mp);
}
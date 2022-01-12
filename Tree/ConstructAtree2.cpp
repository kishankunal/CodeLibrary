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
//inorder and post order is given
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return buildTrees(inorder, 0, n-1, postorder, 0, n-1, mp);
    }
    TreeNode* buildTrees(vector<int>& inorder, int inStart, int inEnd, vector<int> &postorder, int poStart, int poEnd, unordered_map<int, int> &mp){
        if(inStart > inEnd || poStart > poEnd){
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[poEnd]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;
        root->left = buildTrees(inorder, inStart, inRoot-1, postorder, poStart, poStart+numLeft-1, mp);
        root->right = buildTrees(inorder, inRoot+1, inEnd, postorder, poStart+numLeft, poEnd-1, mp);
        return root;
    }
};
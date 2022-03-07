//https://www.codingninjas.com/codestudio/problems/subtree-of-another-tree_893071?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;



template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};


bool isIdentical(TreeNode<int> *t, TreeNode<int> *s){
    if(!t || !s){
        return t==s;
    }
    return (t->val == s->val) && isIdentical(t->left, s->left) &&isIdentical(t->right, s->right);
}

bool isSubtree(TreeNode<int> *T, TreeNode<int> *S)
{
    if(!S){
        return true;
    }
    if(!T){
        return false;
    }
    if(isIdentical(T, S)){
        return true;
    }
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}
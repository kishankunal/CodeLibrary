#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    treeNode* left = NULL;
    treeNode* right = NULL;
    int data = 0;
};



void allTraversal(treeNode* root){
    stack<pair<treeNode*, int>> stk;
    vector<int> inorder; // left, root, right
    vector<int> postorder; // left, right, root
    vector<int> preorder; // root, left, right
    if(!root){
        return;
    }
    stk.push({root, 1});
    while(!stk.empty()){
        pair<treeNode*, int> x = stk.top();
        stk.pop();
        if(x.second == 1){
            preorder.push_back(x.first->data);
            stk.push({x.first, 2});
            if(x.first->left){
                stk.push({x.first->left, 1});
            }
        }
        else if(x.second ==2){
            inorder.push_back(x.first->data);
            stk.push({x.first, 3});
            if(x.first->right){
                stk.push({x.first->right, 1});
            }
        }
        else{
            postorder.push_back(x.first->data);
        }
    }
}

int main(){

}
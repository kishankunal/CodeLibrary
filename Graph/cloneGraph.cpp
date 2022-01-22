//https://www.interviewbit.com/problems/clone-graph/

#include<bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
UndirectedGraphNode *clone(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &check){
    if(check.find(node)!=check.end()) return check[node];
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    check[node] = newNode;
    for(auto &c: node->neighbors){
        newNode->neighbors.push_back(clone(c, check));
    }
    return check[node];
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> check;
    return clone(node, check);
}




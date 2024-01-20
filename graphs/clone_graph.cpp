#include<bits/stdc++.h>

using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class sol {
    public:
    Node* cloneGraph(Node* node){
        unordered_map<Node*, Node*> hashTable;
        return dfs(node, hashTable)
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*> &hashtable)
    {
        if(!node) return NULL;
        if(hashtable.size()) return hashtable[node];
        Node* clone = new Node(node->val);
        hashtable[node] = clone;
        for (auto n: node->neighbors){
            clone->neighbors.push_back(dfs(n, hashtable));
        }
        return clone;
    }
}

/*
int main(){

}*/
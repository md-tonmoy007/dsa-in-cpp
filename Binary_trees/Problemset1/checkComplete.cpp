// Approach-1 : BFS
#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int countNodes(Node* root){
    if (root == NULL) return 0;

    return 1+countNodes(root->left) + countNodes(root->right);
}

bool isCompleteDFS(Node* root, int index, int totalNodes){
    if (root == NULL) return false;
    
    if (index > totalNodes){
        return false;
    }

    return isCompleteDFS(root->left, 2*index+1, totalNodes) && isCompleteDFS(root->right, 2*index+2, totalNodes);
}


int main(){
    Node* root = NULL;
    root = buildTree(root);

    int totalNodes = countNodes(root);
    
    cout << "is it a CBT:  " << isCompleteDFS(root, 0, totalNodes);
}


// Approach-1 : BFS
#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int countNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return left + right + 1;
}



bool isCBT(Node* root, int index, int cnt) {
    if(root == NULL) {
        return true;
    }

    if(index > cnt) {
        return false;
    }

    bool left = isCBT(root->left, 2*index + 1, cnt);
    bool right = isCBT(root->right, 2*index + 2, cnt);

    return left && right;
}


bool isHeap(Node* root){
    if (root == NULL) return true;

    if (root->left == NULL && root->right == NULL){
        return true;
    }
    if (root->right == NULL ) return root->data > root->left->data;

    bool left = isHeap(root->left);
    bool right = isHeap(root->right);

    bool curr = (root->left->data < root->data && root->right->data < root->data);

    return left && right && curr;

}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    int totalNodes = countNodes(root);
    
    cout << "is it a CBT:  " << isCBT(root, 0, totalNodes);
    cout << "is it a HEAP: " << isHeap(root);
}


#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;


bool checkBST(Node* root){
    if(root == NULL) return true;
    if(root->left != NULL && root->left->data > root->data) return false;
    if(root->right != NULL && root->right->data < root->data) return false;

    bool left = checkBST(root->left);
    bool right = checkBST(root->right);

    return (left && right);
}


int main(){

    Node* root = NULL;
    root = buildTree(root);

    cout << "the binary is a BST: " << checkBST(root) << endl;
}
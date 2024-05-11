#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int getHeight(Node* root){
    if (root == NULL){
        return 0; 
    }

    int left = getHeight(root->left);
    int right= getHeight(root->right);

    int height = max(left, right) + 1;

    return height;
}


int main() {
    Node* root = NULL;

    root = buildTree(root);

    int height = getHeight(root);
    cout << endl << "Height / Depth of the tree is : " << height << endl;

    return 0;
}

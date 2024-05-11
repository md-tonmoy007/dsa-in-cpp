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

int getDiameter(Node* root){
    if (root == NULL){
        return 0;
    }

    int D1 = getDiameter(root->left);
    int D2 = getDiameter(root->right);

    int D3 = getHeight(root->left) + getHeight(root->right) + 1;

    int ans = max(D3, max(D1, D2));
    return ans;
}



int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout << "diameter of the tree is : " << getDiameter(root) << endl;
}

// Enter the data : 1 2 4 8 -1 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 
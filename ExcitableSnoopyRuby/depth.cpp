#include<bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int depth(Node* root, int x){
    if(root == NULL){
        return -1;
    }

    int dist = -1;
    if((root->data == x) || (dist=depth(root->left, x))>=0 || (dist=depth(root->right, x))>=0){
        return dist+1;
    }

    return dist;
}


int main(){
    Node* root = NULL;
    root = buildTree(root);


    int depthOfBT= depth(root, 5);
    cout << "depth of BT:  "<< depthOfBT << endl;
}
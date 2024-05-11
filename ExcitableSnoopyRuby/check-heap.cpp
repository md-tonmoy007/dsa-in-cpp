#include<bits/stdc++.h>
#include "BinaryTree.h"


using namespace std;

int CountNodes(Node* root){
    if(root == NULL) return 0;
    int right = CountNodes(root->right);
    int left = CountNodes(root->left);

    return right+left+1;
}

bool isCBT(Node* root,int index, int totalNodes){
    if(root == NULL) return true;

    if(index > totalNodes) return false;

    bool right = isCBT(root->right, 2*index+2, totalNodes);
    bool left = isCBT(root->left, 2*index+1, totalNodes);

    return right && left;
}

bool isMaxHeap(Node* root){
    if(root == NULL) return true;
    if(root->right == NULL && root->left == NULL) return true;

    if (root->right == NULL) return (root->data > root->left->data);


    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);

    bool curr = (root->data > root->left->data) && (root->data > root->right->data);

    return left && right && curr;
}



int main(){

    Node* root = NULL;
    root = buildTree(root);

    int cnt = CountNodes(root);

    cout << endl << "is it a CBT: " << isCBT(root, 0, cnt) << endl;
    if(isCBT){
        cout << endl << "is it a HEAP:  " << isMaxHeap(root)<< endl;
    }


}
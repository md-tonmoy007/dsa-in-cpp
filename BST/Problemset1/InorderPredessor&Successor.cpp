#include <bits/stdc++.h>
#include "BST.h"

using namespace std;

pair<int, int> predecessorSuccessor(Node *root, int key)
{
    Node *keynode = root;
    int pred = -1;
    int succ = -1;
    while (keynode->data != key)
    {

        if (keynode->data > key)
        {
            succ = keynode->data;
            keynode = keynode->left;
        }
        else
        {
            pred = keynode->data;
            keynode = keynode->right;
        }
        
    }

    Node* leftTree = keynode->left;
    while (leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }


    Node* rightTree = keynode->right;
    while (rightTree != NULL){
        pred = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}

int main()
{
    Node* root = NULL;
    int key;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << "Enter the value of key element : ";
    cin >> key;

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    int index = 0;
    pair<int, int> ans = predecessorSuccessor(root, key);

    cout << "Predecessor : " << ans.first << endl;
    cout << "Successor   : " << ans.second << endl;
    return 0;
}
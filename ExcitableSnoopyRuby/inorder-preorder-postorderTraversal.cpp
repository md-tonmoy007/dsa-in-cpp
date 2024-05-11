#include<bits/stdc++.h>
#include "BinaryTree.h"


using namespace std;

void inorder(Node* root){
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if (root == NULL) return;

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}


void postOrder(Node* root){
    if (root == NULL) return;

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}


// using stack

void inorderStack(Node* root){
    stack<Node*>st;
    Node* curr = root;
    while(curr != NULL && !st.empty()){
        while (curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;     
    }
}

void preOrderStack(Node* root) 
{
    if (root == NULL) 
        return;
    
    stack<Node*> treeStack;
    Node* currNode = root;
    Node* prevNode = NULL;
  
    while (treeStack.empty() == false || currNode != NULL) 
    {
        if (currNode != NULL) 
        {
            cout << currNode->data << " ";
            treeStack.push(currNode);
            currNode = currNode->left;
        }
        else 
        {
            prevNode = treeStack.top();
            treeStack.pop();
            currNode = prevNode->right;
        }
    }
}


void PostOrderStack(Node* root) 
{
    if (root == NULL)
        return;
        
    stack<Node*> mainStack;
    stack<Node*> rightChildStack;
    Node* currNode = root;
    
    while (mainStack.empty() == false || currNode != NULL) 
    {
        if (currNode != NULL) 
        {
            if (currNode->right != NULL)
                rightChildStack.push(currNode->right);
            
            mainStack.push(currNode);
            currNode = currNode->left;
        } 
        else 
        {
            currNode = mainStack.top();
            if (rightChildStack.empty() == false && currNode->right == rightChildStack.top()) 
            {
                currNode = rightChildStack.top();
            } 
            else 
            {
                cout << currNode->data << " ";
                mainStack.pop();
                currNode = NULL;
            }
        }
    }
}


int main(){

    Node* root = NULL;
    root = buildTree(root);

    cout << endl << endl;

    cout << "inorder: " << endl;
    inorder(root);
    cout << endl;
    cout << "postOrder: " << endl;
    postOrder(root);
    cout << endl;
    cout << "preOrder: " << endl;
    preorder(root);
    cout << endl;


}
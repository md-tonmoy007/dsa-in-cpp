#include<bits/stdc++.h>

using namespace std;

class node {
    public:
        string data;
        node* left;
        node* right;

    node(string d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    string data;
    cin >> data;
    root = new node(data);    

    if(data == "null") {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void inorder(node* root) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    if(root == NULL) {
        return ;
    }
    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    if(root == NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main(){
    node* root = NULL;

    root = buildTree(root);
    cout << "printing in order" << endl;
    inorder(root);
    cout << endl;
    cout << "printing pre-order" << endl;
    preorder(root);
    cout << endl;
    cout << "printing post-order" << endl;
    postorder(root);
    cout << endl;

}
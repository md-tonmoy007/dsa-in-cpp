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


int main(){
    node* root = NULL;

    root = buildTree(root);


}
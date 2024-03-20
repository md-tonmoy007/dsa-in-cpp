#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
	Node* left;
	Node* right;
    Node(int d){
        this->data=d;
        this->left= nullptr;
        this->right= nullptr;
    }
};

bool solve(Node * root) {
        if (root == NULL) return true;
        if (root->left != NULL && root->left->data > root->data) return false;
        if (root->right != NULL && root->right->data < root->data) return false;
        bool left = solve(root->left);
        bool right = solve(root->right);

        return (left && right);
    }



int main()
{
    Node* root;
    root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    if(solve(root)){
        cout << "it is a bst";
    }else cout << "not a bst" << endl;

}


#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* travptr, int data) {
        if (travptr == nullptr) {
            travptr = new Node(data);
            return travptr;
        }
        (data > travptr->data) ? travptr->right = insert(travptr->right, data) : travptr->left = insert(travptr->left, data);
        return travptr;
    }

    bool contains(Node* travptr, int data) {
        if (travptr == nullptr)
            return false;
        if (data == travptr->data)
            return true;
        return (data > travptr->data) ? contains(travptr->right, data) : contains(travptr->left, data);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    bool contains(int data) {
        return contains(root, data);
    }
};

int main() {
    BinaryTree bst;

    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);

    cout << bst.contains(3) << "\t" << bst.contains(10) << "\t" << bst.contains(5);

    return 0;
}

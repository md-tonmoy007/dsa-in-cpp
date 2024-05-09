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

int depth(Node * root, int x) {
        if (root == NULL) return -1;
        int dist = -1;
        if ((root->data == x)
        || (dist = depth(root->left, x)) >= 0
        || (dist = depth(root->right, x)) >= 0)

        return dist + 1;
 
    return dist;
    }


int depthez(Node* root, int x){

    if(root == NULL) return -1;
    int dist = -1;

    if(root->data == x){
        return dist+1;
    }

    dist = depthez(root->left, x);
    if (dist >= 0){
        return dist+1;
    }

    dist = depthez(root->right, x);
    if (dist >= 0){
        return dist+1;
    }

    return dist;
}
int findHeightUtil(Node* root, int x, int& height)
{
    if (root == NULL) {
        return -1;
    }
    int leftHeight = findHeightUtil(
        root->left, x, height);
 
    int rightHeight
        = findHeightUtil(
            root->right, x, height);
     int ans = max(leftHeight, rightHeight) + 1;

     if (root->data == x)
        height = ans;
 
    return ans;
}
int findHeight(Node* root, int x)
{
    int h = -1;

    int maxHeight = findHeightUtil(root, x, h);

    return h;
}


int main()
{
    Node* root;
    root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->left->right = new Node(25);
    root->left->right->right = new Node(45);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    cout << depth(root, 25) << endl; 
    cout << depthez(root, 25) << endl;
    cout << findHeight(root, 5) << endl;
}
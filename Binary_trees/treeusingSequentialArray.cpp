#include<bits/stdc++.h>

using namespace std;
string tree[100];

void buildTreeUsingArray(int root) {

    cout << "Enter the data: " << endl;
    string data;
    cin >> data;

    tree[root] = data;
    if (data == "null"){
        return;
    }

    
    cout << "Enter data for inserting in left of " << data << endl;
    buildTreeUsingArray(2*root+1);
    cout << "Enter data for inserting in right of " << data << endl;
    buildTreeUsingArray(2*root+2);
    return;
}

void inorder(int root) {
    if(tree[root] == "null") {
        return ;
    }
    inorder(2*root+1);
    cout << tree[root] << " ";
    inorder(2*root+2);

}

void preorder(int root) {
    if(tree[root] == "null") {
        return ;
    }
    cout << tree[root] << " ";
    inorder(2*root+1);
    inorder(2*root+2);

}

void postorder(int root) {
    if(tree[root] == "null") {
        return ;
    }
    cout << tree[root] << " ";
    inorder(2*root+1);
    inorder(2*root+2);

}




int main(){
    int root = 0;

    buildTreeUsingArray(root);
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
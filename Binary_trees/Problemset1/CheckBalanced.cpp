#include <bits/stdc++.h>
#include "BinaryTree.h"
 
using namespace std;
 


int getHeight(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    int answer = max(left, right) + 1;
    return answer;
}

bool isBalanced(Node* root){
    if (root == NULL){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(getHeight(root->left) - getHeight(root->right)) <= 1;
    if (left && right && diff){
        return 1;
    }
    else {
        return false;
    }
}


int main(){
    return 0;
}
// Approach-1 : BFS
#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

bool isCompleteTree(Node *root)
{
    // Using BFS

    queue<Node *> que;

    que.push(root);

    bool past = false; // kya aapne past me NULL node dekha hai ?

    while (!que.empty())
    {
        Node *node = que.front();
        que.pop();

        if (node == NULL)
        {
            past = true;
        }
        else
        {
            if (past == true)
            {
                return false;
            }

            que.push(node->left);
            que.push(node->right);
        }
    }

    return true;
}


bool isCompleteBFS(Node* root){
    queue<Node*> que;
    que.push(root);
    bool past = false;
    while(!que.empty()){
        Node* node = que.front();
        que.pop();
        if(node == NULL){
            past = true;
        }else{
            if(past == true){
                return false;
            }
        }

        que.push(node->left);
        que.push(node->right);
    }
    
}

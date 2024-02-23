#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
};

struct node* createNode(char data) {
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%c", root->data); // Print data before traversing subtrees
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode('A');
    struct node *p1 = createNode('B');
    struct node *p2 = createNode('C');

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    // Constructing the left subtree
    p1->left = createNode('D');
    p1->right = createNode('E');

    // Constructing the right subtree
    p2->left = createNode('F');
    p2->left->right = createNode('G');
    p2->left->right->left = createNode('F');
    p2->left->right->right = createNode('G');

    printf("Output: ");
    preOrderTraversal(p); // Output: ABDEHJCFIG
    printf("\n");

    return 0;
}
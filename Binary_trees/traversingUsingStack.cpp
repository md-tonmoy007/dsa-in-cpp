#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        cout << node->val << " ";
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> stk;
    stack<int> out;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        out.push(node->val);
        if (node->left) stk.push(node->left);
        if (node->right) stk.push(node->right);
    }
    while (!out.empty()) {
        cout << out.top() << " ";
        out.pop();
    }
}

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    while (curr != nullptr || !stk.empty()) {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

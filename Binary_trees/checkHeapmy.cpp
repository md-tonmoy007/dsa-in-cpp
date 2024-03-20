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

unsigned int countNodes(Node* root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left)
			+ countNodes(root->right));
}

bool isCompleteUtil(Node* root, unsigned int index, unsigned int number_nodes)
{
    if (root == NULL)
		return (true);
    if (index >= number_nodes)
		return (false);

    return (isCompleteUtil(root->left, 2 * index + 1,
						number_nodes)
			&& isCompleteUtil(root->right, 2 * index + 2,
							number_nodes));
}

bool isHeapUtil(Node* root)
{
	if (root->left == NULL && root->right == NULL)
		return (true);


	if (root->right == NULL) {
	
		return (root->data >= root->left->data);
	}
	else {

		if (root->data >= root->left->data
			&& root->data >= root->right->data)
			return ((isHeapUtil(root->left))
					&& (isHeapUtil(root->right)));
		else
			return (false);
	}
}


bool isHeap( Node* root)
{

	unsigned int node_count = countNodes(root);
	unsigned int index = 0;

	if (isCompleteUtil(root, index, node_count)
		&& isHeapUtil(root))
		return true;
	return false;
}

int main()
{
    Node* root;
    root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);

    cout << countNodes(root) << endl;
    cout << isCompleteUtil(root, 0, 10) << endl;
    cout << isHeapUtil(root) << endl;
    if (isHeap(root))
		cout << "Given binary tree is a Heap\n";
	else
		cout << "Given binary tree is not a Heap\n";

	return 0;

}
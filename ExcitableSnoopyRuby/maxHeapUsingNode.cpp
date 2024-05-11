// #include<bits/stdc++.h>


// using namespace std;


// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node* parent;

//     Node(int data){
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//         this->parent = NULL;

//     }
// };


// class maxHeap{

//     void heapUp(Node* root){
//         while (index > 0 && heap[par(index)]  < heap[index]){
//             swap(heap[par(index)], heap[index]);
//             index = par(index);
//         }
//     }

//     void heapDown(int index, int size){
//         int left = leftChild(index);
//         int right = rightChild(index);

//         int largest = index;

//         if(right < size && heap[right] > heap[index]) largest = right;
//         if (left < size && heap[left] > heap[largest]) largest = left;
//         if (largest != index){
//             swap(heap[index], heap[largest]);
//             heapDown(largest, size);
//         }

//     }
// };


// Node* buildTree(Node* root, Node* parent = NULL){
//     int data;
//     cout << "Enter the data : ";
//     cin >> data;
//     root = new Node(data);

//     if(data == -1) {
//         return NULL;
//     }

//     root->parent = parent;

//     cout << "LEFT of " << data << " : ";
//     root->left = buildTree(root->left, root);
    
//     cout << "RIGHT of " << data << " : ";
//     root->right = buildTree(root->right, root);

//     return root;


// }

// int main() {
//     Node* root = NULL;
//     root = buildTree(root);
    
//     cout << root->left->parent->data << endl;
//     // Maxheap h;
//     // h = constructHeap(arr);

//     // h.display();
//     // h.insert(45);
//     // h.display();
//     // h.remove(45);
//     // h.display();
//     // h.heapSort();

//     // heapSort(h);


// }
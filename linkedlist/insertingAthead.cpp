#include <iostream>

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to traverse and print the elements of the list
    void traverse() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a linked list
    LinkedList myList;

    // Insert elements at the head of the linked list
    myList.insertAtHead(3);
    myList.insertAtHead(2);
    myList.insertAtHead(1);

    // Traverse and print the linked list
    myList.traverse();

    return 0;
}

#include <iostream>

using namespace std;
// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() {head = nullptr;}

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insertAt_nth(int value, int n){
        Node* temp1 = new Node(value);
        if(n == 1){
            temp1->next = head;
            head = temp1;
            return;
        }

        Node* temp2 = head;
        for (int i = 0; i < n-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
    
    void DeleteAt_nth(int n){
        Node* temp1 = head;
        if(n==1){
            head = temp1->next;
            delete(temp1);
            return;
        }
        for(int i = 0; i < n-2; i++){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
    }

    // Function to traverse and print the elements of the list
    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a linked list
    LinkedList myList;

    // Insert elements into the linked list
    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);
    myList.insertAtEnd(6);
    myList.insertAtEnd(7);
    myList.insertAtEnd(8);
    myList.insertAtEnd(9);
    
    // Traverse and print the linked list
    myList.traverse();
    myList.insertAt_nth(11, 2);
    myList.traverse();
    myList.DeleteAt_nth(2);
    myList.traverse();

    return 0;
}

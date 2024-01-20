#include<bits/stdc++.h>
#include<iostream>
 
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}


    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }


    void traverse() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void traverseRecursive(Node* n){
        if(n == NULL) {
            cout << endl;
            return;
        }
        cout << n->data << " ";
        traverseRecursive(n->next);
    }

    void reverseIterative(){
        Node *current, *prev, *nxt;
        current = head;
        prev = NULL;
        while(current){
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }

        head = prev;
        return;
    }


    void reverseRecursive(Node* n){
        if(n == NULL) {
            return;
        }
        reverseRecursive(n->next);
        cout << n->data << " ";
    }
};

int main(){
    LinkedList myList;
    myList.insertAtHead(3);
    myList.insertAtHead(2);
    myList.insertAtHead(1);
    
    myList.traverseRecursive(myList.head);
    myList.traverse();
    myList.reverseRecursive(myList.head);

    
}
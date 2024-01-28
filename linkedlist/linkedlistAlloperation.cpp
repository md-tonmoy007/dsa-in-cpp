#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            return;
        }

        if (position == 1 || head == nullptr) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;

        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteFromBeginning() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteFromEnd() {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    void deleteAtPosition(int position) {
        if (head == nullptr || position <= 0) {
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtBeginning(3);
    myList.display();

    myList.insertAtBeginning(7);
    myList.display();

    myList.insertAtBeginning(1);
    myList.display();

    myList.insertAtEnd(5);
    myList.display();

    myList.insertAtEnd(9);
    myList.display();

    myList.insertAtPosition(4, 2);
    myList.display();

    myList.insertAtPosition(8, 4);
    myList.display();

    myList.deleteFromBeginning();
    myList.display();

    myList.deleteFromEnd();
    myList.display();

    myList.deleteAtPosition(3);
    myList.display();

    return 0;
}

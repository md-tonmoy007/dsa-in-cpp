#include <iostream>

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node with given data
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new node at the specified position
    void insertAtPosition(int value, int position) {
        // Create a new node with the given value
        Node* newNode = new Node(value);

        // If the list is empty or position is 0, insert at the head
        if (head == nullptr || position == 0) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            // Traverse to the position in the list
            Node* current = head;
            int currentPosition = 0;
            while (currentPosition < position - 2 && current->next != nullptr) {
                current = current->next;
                currentPosition++;
            }

            // Update pointers to insert at the specified position
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;

    // Insert elements at specific positions in the list
    myList.insertAtPosition(3, 1);   // Insert at head
    myList.insertAtPosition(7, 2);   // Insert at position 1
    myList.insertAtPosition(1, 2);   // Insert between nodes

    // Display the list
    std::cout << "Doubly Linked List: ";
    myList.display();

    return 0;
}

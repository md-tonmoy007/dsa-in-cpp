#include <iostream>

using namespace std;

// Define a node class for the stack
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Define the Stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack
    
public:
    // Constructor
    Stack() {
        top = nullptr;
    }
    
    // Destructor
    ~Stack() {
        // Free memory allocated to the stack nodes
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    // Push operation to add a node to the top of the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
    // Pop operation to remove the top node from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    // Function to show the top node of the stack
    void showTop() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
};

int main() {
    Stack stack;
    
    stack.push(5);
    stack.push(10);
    stack.push(15);
    
    stack.showTop(); // Should print 15
    
    stack.pop();
    stack.showTop(); // Should print 10
    
    stack.pop();
    stack.showTop(); // Should print 5
    
    stack.pop();
    stack.showTop(); // Should indicate that the stack is empty
    
    return 0;
}

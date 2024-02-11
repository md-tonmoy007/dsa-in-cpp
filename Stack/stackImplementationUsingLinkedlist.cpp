#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};


class Stack {
private:
    Node* top;
    
public:

    Stack() {
        top = nullptr;
    }
    

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    

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
    
    stack.showTop();
    
    stack.pop();
    stack.showTop();
    
    stack.pop();
    stack.showTop();
    
    stack.pop();
    stack.showTop();
    
    return 0;
}

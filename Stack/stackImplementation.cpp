#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;
    
public:
    Stack() {
        top = -1;
    }
    
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow. Cannot push." << endl;
            return;
        }
        arr[++top] = value;
    }
    
    void pop() {
        if (top == -1) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        --top;
    }
    
    void showTop() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
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

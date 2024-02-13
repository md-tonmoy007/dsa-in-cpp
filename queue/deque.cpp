#include <iostream>
#include <stdexcept>

class CircularDeque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    CircularDeque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularDeque() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void insertFront(int element) {
        if (isFull()) {
            throw std::overflow_error("Deque is full");
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = element;
    }

    void insertRear(int element) {
        if (isFull()) {
            throw std::overflow_error("Deque is full");
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = element;
    }

    int deleteFront() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty");
        }

        int element = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        return element;
    }

    int deleteRear() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty");
        }

        int element = arr[rear];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        return element;
    }

    int getFront() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty");
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty");
        }
        return arr[rear];
    }
};

int main() {
    CircularDeque deque(5);

    deque.insertRear(5);
    deque.insertRear(10);
    deque.insertFront(15);
    deque.insertFront(20);

    std::cout << "Front element: " << deque.getFront() << std::endl;
    std::cout << "Rear element: " << deque.getRear() << std::endl;

    std::cout << "Deleted front element: " << deque.deleteFront() << std::endl;
    std::cout << "Deleted rear element: " << deque.deleteRear() << std::endl;

    std::cout << "Front element: " << deque.getFront() << std::endl;
    std::cout << "Rear element: " << deque.getRear() << std::endl;

    return 0;
}
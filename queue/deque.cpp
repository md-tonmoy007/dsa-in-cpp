#include <iostream>

using namespace std;

class Deque {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int size;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        frontIndex = -1;
        rearIndex = 0;
        size = 0;
    }



    void push_front(int element) {
        if (isFull()) {
            std::cout << "Deque is full" << std::endl;
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;

        

        frontIndex = (frontIndex - 1 + capacity) % capacity;
        cout <<"push front: " <<  frontIndex << endl;
        arr[frontIndex] = element;
        size++;
    }

    void push_back(int element) {
        if (isFull()) {
            std::cout << "Deque is full" << std::endl;
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = element;
        size++;
    }

    void pop_front() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }

        if (frontIndex == rearIndex)
            frontIndex = rearIndex = -1;
        else
            frontIndex = (frontIndex + 1) % capacity;
            cout <<"pop front: "<<  frontIndex << endl;

        size--;
    }

    void pop_back() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }

        if (frontIndex == rearIndex)
            frontIndex = rearIndex = -1;
        else
            rearIndex = (rearIndex - 1 + capacity) % capacity;

        size--;
    }

    int front() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }
        return arr[frontIndex];
    }

    int back() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }
        return arr[rearIndex];
    }

    bool isEmpty() {
        return frontIndex == -1;
    }

    bool isFull() {
        return (frontIndex == 0 && rearIndex == capacity - 1) || (frontIndex == rearIndex + 1);
    }

    int getSize() {
        return size;
    }
};

int main() {
    Deque myDeque(10);

    myDeque.push_front(10);
    myDeque.push_front(20);
    myDeque.push_back(30);
    myDeque.push_front(40);
    myDeque.push_back(50);
    myDeque.push_back(60);
    myDeque.push_front(70);
    myDeque.push_back(80);

    

    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    myDeque.pop_front();

    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;
    
    myDeque.pop_front();

    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    myDeque.pop_front();

    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    myDeque.pop_front();

    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    return 0;
}

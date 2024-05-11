#include<bits/stdc++.h>

using namespace std;

class MaxHeap {
private:
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }
    void goingUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
    void goingDown(int index, int size) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;
        if (left < size && heap[left] > heap[index])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        if (largest != index) {
            swap(heap[index], heap[largest]);
            goingDown(largest, size);
        }
    }
public:
    vector<int> heap;
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        goingUp(index);
    }
    void remove(int value) {
        auto it = find(heap.begin(), heap.end(), value);
        if (it != heap.end()) {
            int index = it - heap.begin();
            swap(heap[index], heap.back());
            heap.pop_back();
            goingDown(index, heap.size());
        } else {
            cout << "Element not found in the heap." << endl;
        }
    }
    int extractMax() {
        if (!heap.empty()) {
            int max = heap[0];
            swap(heap[0], heap.back());
            heap.pop_back();
            goingDown(0, heap.size());
            return max;
        } else {
            cout << "Heap is empty.";
            return -1;
        }
    }
    bool isEmpty() {
        return heap.empty();
    }
    void display(){
        vector<int>::iterator iter = heap.begin();
        for (iter; iter<heap.end(); iter++){
            cout << *iter << " ";
        }
        cout << endl;
    }


    void DangerousHeapSort(){
        for(int i = 0; i < heap.size(); i++){
            int max = extractMax();
            cout << max << " ";
        }
        cout << endl;
    }

};

MaxHeap constructHeap(vector<int>& arr) {
    MaxHeap heap;
    for (int num : arr) {
        heap.insert(num);
    }

    return heap;
    

}




int main() {
    vector<int> arr = {44, 30, 50, 22, 60, 55, 77};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    MaxHeap h;
    cout << endl;
    h = constructHeap(arr);
    h.display();
    cout << endl;
    h.remove(30);
    cout << "display after deleting 22" << endl;
    h.display();
    cout << endl;
    cout << "printing after heap sort" << endl;

    cout << endl;
    cout << endl;

    return 0;
}

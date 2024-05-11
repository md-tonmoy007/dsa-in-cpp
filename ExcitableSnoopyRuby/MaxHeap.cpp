#include<bits/stdc++.h>


using namespace std;



class Maxheap{
    int par(int i){ return (i-1)/2;}
    int leftChild(int i){ return (2*i+1);}
    int rightChild(int i) { return (2*i+2);}


    void heapUp(int index){
        while (index > 0 && heap[par(index)]  < heap[index]){
            swap(heap[par(index)], heap[index]);
            index = par(index);
        }
    }

    void heapDown(int index, int size){
        int left = leftChild(index);
        int right = rightChild(index);

        int largest = index;

        if(right < size && heap[right] > heap[index]) largest = right;
        if (left < size && heap[left] > heap[largest]) largest = left;
        if (largest != index){
            swap(heap[index], heap[largest]);
            heapDown(largest, size);
        }

    }
    public:
    vector<int>heap;
    void insert(int v){
        heap.push_back(v);
        int index = heap.size() - 1;
        heapUp(index);

    }

    void remove (int v){
        auto it = find(heap.begin(), heap.end(), v);
        if(it != heap.end()){
            int index = it-heap.begin();
            swap(heap[index], heap.back());
            heap.pop_back();
            heapDown(index, heap.size());

        }else{
            cout << "Value not found" << endl;
        }
    }

    int extractMax(){
        if (!heap.empty()) {
            int max = heap[0];
            swap(heap[0], heap.back());
            heap.pop_back();
            heapDown(0, heap.size());
            return max;
        } else {
            cout << "Heap is empty.";
            return -1;
        }
    }

    void display(){
        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i] << " " ;

        }
        cout << endl;
    }

    void heapSort(){
        cout << heap.size() << endl;
        for(int i = 0; i < heap.size(); i++){
            int max = extractMax();
            cout << max  << " " << i << " ";
        }
        cout << endl;
    }

};


void heapSort(Maxheap MH) {
    vector<int> heap = MH.heap;
    int arr[heap.size()];
    for (int i = 0; i < heap.size(); i++) {
        arr[i] = MH.extractMax();
        cout << arr[i] << " "; 
    }
    cout << endl;
}


Maxheap constructHeap(vector<int>& arr) {
    Maxheap heap;
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
    cout << endl;

    Maxheap h;
    h = constructHeap(arr);

    // h.display();
    // h.insert(45);
    // h.display();
    // h.remove(45);
    // h.display();
    // h.heapSort();

    heapSort(h);


}
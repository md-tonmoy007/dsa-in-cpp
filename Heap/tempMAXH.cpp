#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
  private:
    int parent(int index){return (index-1)/2;}
    int leftChild(int index){return 2*index+1;}
    int rightChild(int index){return 2*index+2;}
    
    void goingUp(int index){
        while (index > 0 && heap[parent(index)] < heap[index]){
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
    
    void goingDown(int index, int size){
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;
        
        if(left < size && heap[left] > heap[index]){ largest = left; }
        if(right<size && heap[right] > heap[largest]){ largest = right; }
        if(largest != index){
            swap(heap[index], heap[largest]);
            goingDown(largest, size);
        }
    }

  public:
    vector<int>heap;
    void insert(int value){
        heap.push_back(value);
        int index = heap.size() - 1;
        goingUp(index);
    }
    
    void remove(int value){
        auto it = find(heap.begin(), heap.end(), value);
        if(it != heap.end()){
            int index = it - heap.begin();
            swap(heap[index], heap.back());
            heap.pop_back();
            goingDown(index, heap.size());
        }else
        {
            cout << "Value not found \n"; 
        }
    }
    
    int extractMax(){
        if (!heap.empty()){
            int max = heap[0];
            swap(heap[0], heap.back());
            heap.pop_back();
            goingDown(0, heap.size());
            return max;
        }else
        {
            cout << "heap is empty\n";
            return -1;
        }
    }
    
    void display(){

        int size = heap.size();
        for (int i = 0; i < size; i++){
            cout << heap[i] << " ";
        }

        vector<int>::iterator itr = heap.begin();
        for(itr; itr < heap.end(); itr++){
            cout << *itr << " ";
        }
        cout << endl ;
    }

    void DangerousHeapSort(){
        for(int i = 0; i < heap.size(); i++){
            int max = extractMax();
            cout << max << " ";
        }
        cout << endl;
    }
    
};


MaxHeap constructHeap(vector<int>& arr){
    MaxHeap h;
    for (int num: arr){
        h.insert(num);
    }
    return h;
}

void heapSort(MaxHeap MH) {
    vector<int> heap = MH.heap;
    int arr[heap.size()];
    for (int i = 0; i < heap.size(); i++) {
        arr[i] = MH.extractMax();
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {44, 30, 50, 22, 60, 55, 77, 55};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    MaxHeap h;
    h = constructHeap(arr);
    h.display();
    h.remove(60);
    h.display();
    // cout << "\nmax: " << h.extractMax() << endl;;
    // h.DangerousHeapSort();
    heapSort(h);
}
#include<iostream>
using namespace std;

#define rn(i, n) for(int i = 0; i < n; i++)

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; //{7, 5, 1, 0, 4, 2, 6, 3};

    int i = low;
    for (int j = low; j < high-1; j++)
    {
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}



int main()
{
    int arr[] = {7, 5, 1, 0, 4, 2, 6, 3};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n-1);
    rn(i, n-1)
    {
        cout << arr[i] << endl;
    }
    
}
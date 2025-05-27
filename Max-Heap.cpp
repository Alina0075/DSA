#include <iostream>
using namespace std;

void manualSwap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void adjustHeap(int heap[], int size, int root) {
    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != root) {
        manualSwap(heap[root], heap[largest]);
        adjustHeap(heap, size, largest);
    }
}

void createMaxHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        adjustHeap(heap, size, i);
    }
}

void insertIntoHeap(int heap[], int& size, int newValue) {
    heap[size] = newValue;
    int index = size;
    size++;

    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        manualSwap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapSortAscending(int heap[], int size) {
    createMaxHeap(heap, size);

    for (int i = size - 1; i > 0; i--) {
        manualSwap(heap[0], heap[i]); 
        adjustHeap(heap, i, 0); 
    }
}


void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    int heap[100]; 

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> heap[i];
    }

    createMaxHeap(heap, size);
    cout << "Max Heap Structure: ";
    displayArray(heap, size);

    int newElement;
    cout << "Enter a new element to insert: ";
    cin >> newElement;
    insertIntoHeap(heap, size, newElement);

    cout << "Heap after insertion: ";
    displayArray(heap, size);

    heapSortAscending(heap, size);
    cout << "Sorted Array (Ascending Order): ";
    displayArray(heap, size);

    return 0;
}

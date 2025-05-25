#include <iostream>
#include <string>

using namespace std;

template <typename T>
void printArray(T array[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
void selectionSort(T array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minimumIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minimumIndex]) {
                minimumIndex = j;
            }
        }
        swap(array[minimumIndex], array[i]);  
    }
}

template <typename t>
void swap(t* a, t* b) {
    t temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Test with an integer array of size 5
    int intArray[5] = { 64, 25, 12, 22, 11 };
    cout << "Original integer array: ";
    printArray(intArray, 5);
    selectionSort(intArray, 5);
    cout << "Sorted integer array: ";
    printArray(intArray, 5);

    // Test with a string array of size 4
    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    cout << "\nOriginal string array: ";
    printArray(stringArray, 4);
    selectionSort(stringArray, 4);
    cout << "Sorted string array: ";
    printArray(stringArray, 4);

    return 0;
}
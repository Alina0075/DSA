#include <iostream>
#include <string>
using namespace std;


template <typename T>
int binarySearch(T array[], int n, T key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == key) {
            return mid; 
        }
        else if (array[mid] < key) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
    return -1;
}

template <typename T>
void printSearchResult(int index, T key) {
    if (index != -1) {
        cout << "Element " << key << " found at index: " << index << endl;
    }
    else {
        cout << "Element " << key << " not found." << endl;
    }
}

int main() {
    // Test with an integer array (sorted) of size 5
    int intArray[5] = { 11, 12, 22, 25, 64 };
    int intKey = 11;
    int intIndex = binarySearch(intArray, 5, intKey);
    printSearchResult(intIndex, intKey);

    // Test with a float array (sorted) of size 4
    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, 4, floatKey);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array (sorted) of size 4
    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, 4, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}

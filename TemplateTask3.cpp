#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template<typename Type>
class list {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    list(int size = 10);
    list(const list& obj);
    virtual void addElementAtFirstIndex(Type value) = 0;
    virtual void addElementAtLastIndex(Type value) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
    ~list();
};

template<typename Type>
list<Type>::list(int size) {
    maxSize = size;
    currentSize = 0;
    arr = new Type[size];
}

template<typename Type>
list<Type>::list(const list& obj) {
    maxSize = obj.maxSize;
    currentSize = obj.currentSize;
    arr = new Type[maxSize];
    for (int i = 0; i < currentSize; i++) {
        arr[i] = obj.arr[i];
    }
}

template<typename Type>
list<Type>::~list() {
    delete[] arr;
}

template<typename Type>
class Mylist : public list<Type> {
public:
    Mylist(int size = 10);
    void addElementAtFirstIndex(Type value);
    void addElementAtLastIndex(Type value);
    Type removeElementFromEnd();
    void removeElementFromStart();
    void display();
    int size();
};

template<typename Type>
Mylist<Type>::Mylist(int size) : list<Type>(size) {}

template<typename Type>
void Mylist<Type>::addElementAtFirstIndex(Type value) {
    for (int i = list<Type>::currentSize; i > 0; i--) {
        list<Type>::arr[i] = list<Type>::arr[i - 1];
    }
    list<Type>::arr[0] = value;
    list<Type>::currentSize++;
}

template<typename Type>
void Mylist<Type>::addElementAtLastIndex(Type value) {
    list<Type>::arr[list<Type>::currentSize] = value;
    list<Type>::currentSize++;
}

template<typename Type>
Type Mylist<Type>::removeElementFromEnd() {
    list<Type>::currentSize--;
    return list<Type>::arr[list<Type>::currentSize];
}

template<typename Type>
void Mylist<Type>::removeElementFromStart() {
    for (int i = 0; i < list<Type>::currentSize - 1; i++) {
        list<Type>::arr[i] = list<Type>::arr[i + 1];
    }
    list<Type>::currentSize--;
}

template<typename Type>
void Mylist<Type>::display() {
    for (int i = 0; i < list<Type>::currentSize; i++) {
        cout << list<Type>::arr[i] << " ";
    }
    cout << endl;
}

template<typename Type>
int Mylist<Type>::size() {
    return list<Type>::currentSize;
}



template<typename Type>
class CustomList : public Mylist<Type> {
public:
    CustomList();
    CustomList(int s);
    ~CustomList();
    bool isPrime(Type n);
    Type sum_ofPrime();
    Type semaxeven();
    int seminOdd();
    void printDuplicates();
    void rotateClockwise(int r);
    void rotateAntiClockwise(int r);
};

// Constructor definitions
template<typename Type>
CustomList<Type>::CustomList() {}

template<typename Type>
CustomList<Type>::CustomList(int s) : Mylist<Type>(s) {}

template<typename Type>
CustomList<Type>::~CustomList() {}

// Method to check if a number is prime
template<typename Type>
bool CustomList<Type>::isPrime(Type n) {
    if (n < 2)
        return false;
    for (Type i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Method to get the sum of prime numbers in the list
template<typename Type>
Type CustomList<Type>::sum_ofPrime() {
    int sum = 0;
    for (int i = 0; i < this->currentSize; ++i) {
        if (isPrime(this->arr[i])) {
            sum += this->arr[i];
        }
    }
    return sum;
}

// Method to get the second maximum even number
template<typename Type>
Type CustomList<Type>::semaxeven() {
    int maxEven = -1;
    int semaxeven = -1;
    for (int i = 0; i < this->currentSize; ++i) {
        if (this->arr[i] % 2 == 0) {
            if (this->arr[i] > maxEven) {
                semaxeven = maxEven;
                maxEven = this->arr[i];
            }
            else if (this->arr[i] > semaxeven && this->arr[i] != maxEven) {
                semaxeven = this->arr[i];
            }
        }
    }
    return semaxeven;
}

// Method to get the second minimum odd number
template<typename Type>
int CustomList<Type>::seminOdd() {
    int minOdd = -1;
    int seMinOdd = -1;
    for (int i = 0; i < this->currentSize; ++i) {
        if (this->arr[i] % 2 != 0) {
            if (minOdd == -1 || this->arr[i] < minOdd) {
                seMinOdd = minOdd;
                minOdd = this->arr[i];
            }
            else if ((seMinOdd == -1 || this->arr[i] < seMinOdd) && this->arr[i] != minOdd) {
                seMinOdd = this->arr[i];
            }
        }
    }
    return seMinOdd;
}

// Method to print duplicates in the list
template<typename Type>
void CustomList<Type>::printDuplicates() {
    bool foundDuplicate = false;
    for (int i = 0; i < this->currentSize; ++i) {
        int count = 1;
        for (int j = i + 1; j < this->currentSize; ++j) {
            if (this->arr[i] == this->arr[j]) {
                count++;
                this->arr[j] = -1;
            }
        }
        if (count > 1) {
            cout << this->arr[i] << " is present " << count << " times." << endl;
            foundDuplicate = true;
        }
    }
    if (!foundDuplicate) {
        cout << "No duplicates found" << endl;
    }
}

// Method to rotate the list clockwise
template<typename Type>
void CustomList<Type>::rotateClockwise(int r) {
    if (this->currentSize == 0) return;
    r = r % this->currentSize;
    int mid = this->currentSize / 2;
    for (int i = 0; i < r; ++i) {
        int temp = this->arr[mid - 1];
        for (int j = mid - 1; j > 0; --j) {
            this->arr[j] = this->arr[j - 1];
        }
        this->arr[0] = temp;
    }

    for (int i = 0; i < r; ++i) {
        int temp = this->arr[this->currentSize - 1];
        for (int j = this->currentSize - 1; j > mid; --j) {
            this->arr[j] = this->arr[j - 1];
        }
        this->arr[mid] = temp;
    }
}

// Method to rotate the list anti-clockwise
template<typename Type>
void CustomList<Type>::rotateAntiClockwise(int rt) {
    if (this->currentSize == 0) return;
    rt = rt % this->currentSize;

    int mid = this->currentSize / 2;

    for (int i = 0; i < rt; ++i) {
        int temp = this->arr[0];
        for (int j = 0; j < mid - 1; ++j) {
            this->arr[j] = this->arr[j + 1];
        }
        this->arr[mid - 1] = temp;
    }

    for (int i = 0; i < rt; ++i) {
        int temp = this->arr[mid];
        for (int j = mid; j < this->currentSize - 1; ++j) {
            this->arr[j] = this->arr[j + 1];
        }
        this->arr[this->currentSize - 1] = temp;
    }
}

int main() {
    CustomList<int> list(10);

    // Hardcoded test data
    list.addElementAtFirstIndex(1);
    list.addElementAtFirstIndex(3);
    list.addElementAtFirstIndex(5);
    list.addElementAtFirstIndex(2);
    list.addElementAtFirstIndex(3);

    cout << "Current list: ";
    list.display();

    cout << "Sum of prime numbers: " << list.sum_ofPrime() << endl;
    cout << "Second maximum even number: " << list.semaxeven() << endl;
    cout << "Second minimum odd number: " << list.seminOdd() << endl;
    cout << "Duplicates: ";
    list.printDuplicates();

    cout << "List after rotating clockwise by 1: ";
    list.rotateClockwise(1);
    list.display();

    cout << "List after rotating anti-clockwise by 1: ";
    list.rotateAntiClockwise(1);
    list.display();

    return 0;
}

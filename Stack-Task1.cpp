#include<iostream>
using namespace std;

template<typename T>
class abstractstack {
protected:
    T* stack;
    int maxsize;
    int currentsize;
public:
    abstractstack(int size) {
        maxsize = size;
        currentsize = 0;
        stack = new T[size];
    };
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~abstractstack() {}
};

#include"abstractstack.h"
template<typename T>
class myStack :public abstractstack<T> {
public:
    myStack(int size) :abstractstack<T>(size) {}
    void push(T value);
    T pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    void display();
};

template<typename T>
void myStack<T>::push(T value) {
    if (!isFull()) {
        abstractstack<T>::stack[abstractstack<T>::currentsize] = value;
        abstractstack<T>::currentsize++;
    }
    else cout << "Stack is full.";
}

template<typename T>
T myStack<T>::pop() {
    T value;
    if (!isEmpty()) {
        abstractstack<T>::currentsize--;
        value = abstractstack<T>::stack[abstractstack<T>::currentsize];
        return value;
    }
    else return -1;
}

template<typename T>
T myStack<T>::top() const {
    return abstractstack<T>::stack[abstractstack<T>::currentsize - 1];
}

template<typename T>
bool myStack<T>::isEmpty()const {
    if (abstractstack<T>::currentsize == 0) {
        return true;
    }
    else return false;
}

template<typename T>
bool myStack<T>::isFull()const {
    if (abstractstack<T>::currentsize == abstractstack<T>::maxsize) {
        return true;
    }
    else return false;
}

template<typename T>
void myStack<T>::display() {
    for (int i = 0; i < abstractstack<T>::currentsize; i++) {
        cout << abstractstack<T>::stack[i] << " ";
    }
}
#include"myStack.h"
int main() {
    myStack<int> obj1(5);
    int value, valuee;
    int choice = 0;
    do {
        cout << "Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Check if empty\n";
        cout << "6. Check if full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj1.push(1);
            obj1.push(2);
            obj1.push(3);
            obj1.push(4);
            obj1.push(5);
            break;
        case 2:
            value = obj1.pop();
            if (!obj1.isEmpty()) // Only print if not empty
                cout << "The popped value is: " << value << endl;
            break;
        case 3:
            valuee = obj1.top();
            if (!obj1.isEmpty()) // Only print if not empty
                cout << "The top value is: " << valuee << endl;
            break;
        case 4:
            obj1.display();
            break;
        case 5:
            cout << (obj1.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 6:
            cout << (obj1.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

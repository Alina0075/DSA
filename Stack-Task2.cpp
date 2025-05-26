#include<iostream>
#include<string>
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
    virtual void reverse() = 0;
    virtual ~abstractstack() {}
};

#include"abstractstack.h"

template<typename T>
class myStack :public abstractstack<T> {
public:
    myStack(int size) :abstractstack<T>(size) {}
    void push(T value);
    void reverse();
    void display();
};

template<typename T>
void myStack<T>::push(T value) {
    if (abstractstack<T>::currentsize != abstractstack<T>::maxsize) {
        abstractstack<T>::stack[abstractstack<T>::currentsize] = value;
        abstractstack<T>::currentsize++;
    }
    else cout << "Stack is full.";
}

template<typename T>
void myStack<T>::reverse() {
    T* stack2;
    int count = abstractstack<T>::currentsize;
    stack2 = new T[abstractstack<T>::currentsize];
    for (int i = 0; i < abstractstack<T>::currentsize; i++) {
        stack2[i] = abstractstack<T>::stack[i];
    }
   
    for (int i = 0; i < abstractstack<T>::currentsize; i++) {
        abstractstack<T>::stack[i] = stack2[--count];
    }
}

template<typename T>
void myStack<T>::display() {
    for (int i = 0; i < abstractstack<T>::currentsize; i++) {
        cout << abstractstack<T>::stack[i] << " ";
    }
}

#include"MyStack.h"

 int main() {
        myStack<string> obj1(4);
        int choice;
        do {
            cout << "Menu: " << endl;
            cout << "Enter 1 to push elments in stack." << endl;
            cout << "Enter 2 to reverse stack" << endl;
            cout << "Enter 3 to display" << endl;
            cout << "Enter 0 to exit" << endl;
            cout << "Enter choice: " << endl;
            cin >> choice;
            switch (choice) {
            case 1:
            {
                obj1.push("Book A");
            obj1.push("Book B");
            obj1.push("Book C");
            obj1.push("book D");
                break;
            }
            case 2: {
                obj1.reverse();
                break;
            }
            case 3:
            {
                obj1.display();
                break;
            }
            }
        }while (choice != 0);  
        return 0;
    }

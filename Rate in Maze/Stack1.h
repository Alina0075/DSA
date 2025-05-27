#include <iostream>
#include <fstream>
using namespace std;

class Stack {
protected:
    int* iStack;
    int* jStack;
    int currentsize;
public:
    Stack(int size);
    virtual void push(int i, int j) = 0;
    virtual void pop(int& i, int& j) = 0;
    virtual bool isEmpty() = 0;
    ~Stack();
};

Stack::Stack(int size) {
    iStack = new int[size];
    jStack = new int[size];
    currentsize = 0;
}

Stack::~Stack() {
    delete iStack;
    iStack = nullptr;
    delete jStack;
    jStack = nullptr;
}

#include"Stack1.h"
class MyStack :public Stack {
public:
    MyStack(int size);
    void push(int i, int j);
    void pop(int& i, int& j);
    bool isEmpty();
};

MyStack::MyStack(int size) :Stack(size) {}

void MyStack::push(int i, int j) {
    Stack::iStack[Stack::currentsize] = i;
    Stack::jStack[Stack::currentsize] = j;
    Stack::currentsize++;
}

void  MyStack::pop(int& i, int& j) {
    if (Stack::currentsize > 0) {
        Stack::currentsize--;
        i = Stack::iStack[currentsize];
        j = Stack::jStack[currentsize];
    }
}

bool MyStack::isEmpty() {
    return Stack::currentsize == 0;
}

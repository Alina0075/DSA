
#include<iostream>
using namespace std;

class queue {
protected:
    int* NameQueue;
    int maxsize;
    int currentsize;
 
public:
    queue(int size) {
        maxsize = size;
        currentsize = 0;
        NameQueue = new int[size];
    };
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int peek() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual ~queue() {}
};


class myQueue :public queue {
public:
    myQueue(int size) :queue(size) {}
    void enqueue(int value);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void display();
};

void myQueue::enqueue(int value) {
    if (!isFull()) {
        queue::NameQueue[queue::currentsize] = value;
        queue::currentsize++;
    }
    else cout << "NameQueue is full.";
}

int myQueue::dequeue() {
    int value = NameQueue[0];
    for (int i = 0; i < currentsize - 1; i++) {
        NameQueue[i] = NameQueue[i + 1];
    }
    currentsize--;
    return value;
}

int myQueue::peek() {
    return queue::NameQueue[queue::currentsize - 1];
}

bool myQueue::isEmpty() {
    if (queue::currentsize == 0) {
        return true;
    }
    else return false;
}

bool myQueue::isFull() {
    if (queue::currentsize == queue::maxsize) {
        return true;
    }
    else return false;
}

void myQueue::display() {
    for (int i = 0; i < queue::currentsize; i++) {
        cout << queue::NameQueue[i] << " ";
    }
}

class stack {
protected:
    char* stac;   // Change to char to handle character data
    int maxsize;
    int cs;  // Current size (or index)

public:
    stack(int size) {
        stac = new char[size];
        maxsize = size;
        cs = 0;
    }

    void push(char value) {  // Change to char
        if (cs < maxsize) {
            stac[cs] = value;
            cs++;
        }
        else {
            cout << "Stack overflow!" << endl;
        }
    }

    char pop() {  // Change return type to char
        if (!empty()) {
            cs--;
            return stac[cs];
        }
        return '\0'; // Return null character if stack is empty
    }

    char top() {  // Change return type to char
        if (!empty()) {
            return stac[cs - 1];
        }
        return '\0'; // Return null character if stack is empty
    }

    bool empty() {
        return cs == 0;
    }

    void display() {
        for (int i = 0; i < cs; i++) {
            cout << stac[i] << " ";
        }

    }
};

int main() {
    myQueue obj1(3);
    obj1.enqueue(1);
    obj1.enqueue(2);
    obj1.enqueue(3);
    obj1.display();

    stack obj2(3);
    while (!obj1.isEmpty()) {
        obj2.push(obj1.dequeue());
    }
    cout << endl;

    while (!obj2.empty()) {
        obj1.enqueue(obj2.pop());
    }

    obj1.display();
    return 0;
}

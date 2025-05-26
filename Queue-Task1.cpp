#include<iostream>
using namespace std;

class queue {
protected:
    string* NameQueue;
    string* Name2queue;
    int maxsize;
    int currentsize;
    int currentsize2;
    int* marks;
    int* time;
public:
    queue(int size) {
        maxsize = size;
        currentsize = 0;
        currentsize2 = 0;
        NameQueue = new string[size];
        Name2queue = new string[size];
        marks = new int[size];
        time = new int[size];
    };
    virtual void enqueue(string value) = 0;
    virtual string dequeue() = 0;
    virtual string peek() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual ~queue() {}
};
#include"queue.h"

class myQueue :public queue {
public:
    myQueue(int size) :queue(size) {}
    void enqueue(string value);
    void enqueue2(string value);
    string dequeue();
    string peek();
    bool isEmpty();
    bool isFull();
    void display();
};

void myQueue::enqueue(string value) {
    if (!isFull()) {
        queue::NameQueue[queue::currentsize] = value;
        queue::currentsize++;
    }
    else cout << "NameQueue is full.";
}


void myQueue::enqueue2(string value) {
    if (!isFull()) {
        queue::Name2queue[queue::currentsize2] = value;
        time[queue::currentsize2] = rand();
        marks[queue::currentsize2] = rand();
        queue::currentsize2++;
    }
    else cout << "Name2Queue is full.";
}

string myQueue::dequeue() {
    string value = NameQueue[0];
    for (int i = 0; i < currentsize - 1; i++) {
        NameQueue[i] = NameQueue[i + 1];
    }
    currentsize--;
    return value;
}



string myQueue::peek() {
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
    for (int i = 0; i < queue::currentsize2; i++) {
        cout << queue::Name2queue[i] << " ";
        cout << marks[i] << " ";
        cout << time[i] << " ";
        cout << endl;
    }
}
#include"myqueue.h"

int main() {
    myQueue obj1(3);
    string value[3], valuee;
    int choice = 0;
    do {
        cout << "Menu:\n";
        cout << "1. enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Enqueue in new queue\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj1.enqueue("Alina");
            obj1.enqueue("Akhtar");
            obj1.enqueue("Hana");
            break;
        case 2:
            for (int i = 0; i < 3; i++) {
                value[i] = obj1.dequeue();
                cout << "The denque value is: " << value[i] << endl;
            }
            break;
        case 3:
            for (int i = 0; i < 3; i++) {
                obj1.enqueue2(value[i]);
            }
            break;
        case 4:
            obj1.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}





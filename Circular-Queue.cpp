#include<iostream>
using namespace std;

class queue {
protected:
    string* Queue;
    int maxsize;
    int currentsize;
    int front, rear;
public:
    queue(int size) {
        maxsize = size;
        currentsize = 0;
        Queue = new string[size];
        front = 0;
        rear = 0;
    }
    virtual void enqueue(string value) = 0;
    virtual string dequeue() = 0;
    virtual string peek() = 0;
    virtual string last() = 0;
    virtual ~queue() {}
};
#include"queue.h"
class myQueue : public queue {
public:
    myQueue(int size) : queue(size) {}
    void enqueue(string value);
    string dequeue();
    string peek();
    string last();
    bool isFull();
    bool isEmpty();
    void display();
};

void myQueue::enqueue(string value) {
    if (!isFull()) {
        Queue[rear] = value;
        rear++;
        currentsize++;
    }
    else {
        cout << "Queue is full." << endl;
    }
}

string myQueue::dequeue() {
    if (isEmpty()) {
        return 0;
    }
    string value = Queue[front];
    front++;
    currentsize--;
    return value;
}

string myQueue::peek() {
    if (isEmpty()) {
        return 0;
    }
    return Queue[front];
}

bool myQueue::isEmpty() {
    return currentsize == 0;
}

bool myQueue::isFull() {
    return currentsize == maxsize;
}

string myQueue::last() {
    if (isEmpty()) {
        return 0;
    }
    return Queue[rear - 1];
}

void myQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i < rear; i++) {
        cout << i % maxsize << " " << Queue[i] << " ";
    }
    cout << endl;
}

#include"myqueue.h"
int main() {
    int size;
    cout << "Enter the size of string: ";
    cin >> size;

    myQueue obj1(size);
    string value;
    int choice = 0;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Peek value\n";
        cout << "5. Last\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < size; i++) {
                cout << "Enter customer name: ";
                cin >> value;
                obj1.enqueue(value);
            }
            break;
        case 2:
            cout << "The dequeued value is: " << obj1.dequeue() << endl;


            break;
        case 3:
            obj1.display();
            break;
        case 4:
            cout << "The value at front is: " << obj1.peek() << endl;


            break;
        case 5:
            cout << "The value at rear is: " << obj1.last() << endl;

        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

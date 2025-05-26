#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class linked {
protected:
    node* head;
    node* tail;
    int count;
public:
    linked() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    virtual void insertathead(int value) = 0;
    virtual void insertattail(int value) = 0;
    virtual int deletefromhead() = 0;
    virtual int deletefromtail() = 0;
};

#include"linked.h"
class linkedlist : public linked {
public:
    linkedlist() : linked() {}

    void insertathead(int value) {
        node* nn = new node;
        nn->data = value;
        nn->next = nullptr;
        if(head == nullptr && tail == nullptr) {
            head = tail = nn;
        }
        else {
            nn->next = head;
            head = nn;
        }
    }

    void insertattail(int value) {
        node* nn = new node;
        nn->data = value;
        nn->next = nullptr;
        if (head == nullptr && tail == nullptr) {
            head = tail = nn;
        }
        else {
            tail->next = nn;
            tail = nn;
        }
    }

    int deletefromhead() {
        if (head == nullptr && tail == nullptr) {
            return NULL;
        }
        int returnValue = head->data;
        node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        return returnValue;
    }

    int deletefromtail() {
        if (head == nullptr && tail == nullptr) {
            return NULL;
        }
        int returnValue = tail->data;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        return returnValue;
    }

    void headnode() {
        if (head)
            cout << "The front element is: " << head->data << endl;
        else
            cout << "Queue is empty!" << endl;
    }

    bool empty() {
        return (head == nullptr);
    }

    void display() {
        node* temp = head;
        if (!temp) {
            cout << "Queue is empty!" << endl;
            return;
        }
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#include"linkedlist.h"
class Queue {
    linkedlist llobj;
public:
    void enqueue(int value) {
        llobj.insertattail(value);
    }

    int dequeue() {
        return llobj.deletefromhead();
    }

    void front() {
        llobj.headnode();
    }

    bool is_empty() {
        return llobj.empty();
    }

    void display() {
        llobj.display();
    }
};

#include"Queue.h"

int main() {
    Queue queue;
    int choice, value;

    while (true) {
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Front Element" << endl;
        cout << "5. Check if Queue is Empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            cout << "Value enqueued." << endl;
            break;
        case 2:
            value = queue.dequeue();
            if (value == -1)
                cout << "Queue is empty! Cannot dequeue." << endl;
            else
                cout << "Value dequeued: " << value << endl;
            break;
        case 3:
            cout << "Queue elements: ";
            queue.display();
            break;
        case 4:
            queue.front();
            break;
        case 5:
            if (queue.is_empty())
                cout << "Queue is empty!" << endl;
            else
                cout << "Queue is not empty!" << endl;
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

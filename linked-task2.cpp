#include<iostream>
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
    virtual void insertattail(int value) = 0;
    virtual int deletefromtail() = 0;
};

#include"linked.h"

class linkedlist : public linked {
public:
    linkedlist() : linked() {}

    void insertattail(int value) {
        node* nn = new node;
        nn->data = value;
        nn->next = nullptr;
        if (head == nullptr && tail == nullptr) {
            head = nn;
            tail = nn;
        }
        else {
            tail->next = nn;
            tail = nn;
        }
    }

    int deletefromtail() {
        node* temp = head;
        if (head == nullptr && tail == nullptr) {
            return NULL;
        }
        else if (head == tail) {
            int returningvalue = tail->data;
            delete tail;
            tail = nullptr;
            head = nullptr;
            return returningvalue;
        }
        else {
            int returningvalue2 = tail->data;
            while (true) {
                if (temp->next->next == nullptr) {
                    break;
                }
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp->next = nullptr;
            return returningvalue2;
        }
    }

    void topnodevalue() {
        if (tail != nullptr) {
            cout << "The Top value is: " << tail->data << endl;
        }
        else {
            cout << "Stack is empty!" << endl;
        }
    }

    bool empty() {
        return (head == nullptr && tail == nullptr);
    }

    void display() {
        node* t = head;
        if (t == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        while (t != nullptr) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

#include"linkedlist.h"

class stack {
public:
    linkedlist obj1;

    void push(int value) {
        obj1.insertattail(value);
    }

    int pop() {
        return obj1.deletefromtail();
    }

    void top() {
        obj1.topnodevalue();
    }

    void empty() {
        if (obj1.empty()) {
            cout << "Stack is empty." << endl;
        }
        else {
            cout << "Stack is not empty." << endl;
        }
    }

    void display() {
        obj1.display();
    }
};

#include"stack.h"

int main() {
    stack stobj;
    int choice, value;

    while (true) {
    
        cout << "1. Push element onto the stack" << endl;
        cout << "2. Pop element from the stack" << endl;
        cout << "3. Display the top element of the stack" << endl;
        cout << "4. Display the stack" << endl;
        cout << "5. Check if the stack is empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stobj.push(value);
            cout << "Value pushed onto the stack." << endl;
            break;
        case 2:
            value = stobj.pop();
            if (value == NULL)
                cout << "Stack is empty!" << endl;
            else
                cout << "Value popped: " << value << endl;
            break;
        case 3:
            stobj.top();
            break;
        case 4:
            cout << "Stack elements: ";
            stobj.display();
            break;
        case 5:
            stobj.empty();
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

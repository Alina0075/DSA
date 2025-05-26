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

public:
    linked() {
        head = nullptr;
        tail = nullptr;
    }

    virtual void InsertAtTail(int value) = 0;
    virtual void InsertAtHead(int value) = 0;
    virtual int DeletefromHead() = 0;
    virtual int DeletefromTail() = 0;
    virtual void insertSorted(int value) = 0;
    virtual void search(int key) = 0;
    virtual void display() = 0;
};

#include"linked.h"
class linkedlist : public linked {
public:
    linkedlist() : linked() {}

    void InsertAtTail(int value) override {
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
        cout << "Node with value " << value << " added to tail." << endl;
    }

    void InsertAtHead(int value) override {
        node* nn = new node;
        nn->data = value;
        nn->next = nullptr;
        if (head == nullptr && tail == nullptr) {
            head = nn;
            tail = nn;
        }
        else {
            nn->next = head;
            head = nn;
        }
        cout << "Node with value " << value << " added to head." << endl;
    }

    int DeletefromHead() override {
        if (head == nullptr && tail == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return NULL;
        }
        node* temp = head;
        int value = head->data;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr; 
        return value;
    }

    int DeletefromTail() override {
        if (head == nullptr && tail == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return NULL;
        }
        if (head == tail) { 
            int value = tail->data;
            delete tail;
            head = tail = nullptr;
            return value;
        }

        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        int value = tail->data;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        return value;
    }

    void insertSorted(int value) override {
        node* nn = new node;
        nn->data = value;
        nn->next = nullptr;
        if (head == nullptr || head->data >= value) {
            nn->next = head;
            head = nn;
            if (tail == nullptr) {
                tail = nn;
            }
            cout << "Node with value " << value << " inserted in sorted order." << endl;
            return;
        }

        node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        nn->next = current->next;
        current->next = nn;
        if (nn->next == nullptr) {
            tail = nn;
        }
        cout << "Node with value " << value << " inserted in sorted order." << endl;
    }

    void search(int key) override {
        node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == key) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (found) {
            cout << "Node with value " << key << " found." << endl;
        }
        else {
            cout << "Node with value " << key << " not found." << endl;
        }
    }

    void display() override {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        node* t = head;
        while (t != nullptr) {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
};

#include"linkedlist.h"

int main() {
    linkedlist obj;
    int choice, value;

    while (true) {
        cout << "1. Insert node at tail" << endl;
        cout << "2. Insert node in sorted order" << endl;
        cout << "3. Delete node from head" << endl;
        cout << "4. Delete node from tail" << endl;
        cout << "5. Search for a node" << endl;
        cout << "6. Display the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            obj.InsertAtTail(value);
            break;

        case 2:
            cout << "Enter value to insert in sorted order: ";
            cin >> value;
            obj.insertSorted(value);
            break;

        case 3:
            cout << "Deleted value from head: " << obj.DeletefromHead() << endl;
            break;

        case 4:
            cout << "Deleted value from tail: " << obj.DeletefromTail() << endl;
            break;

        case 5:
            cout << "Enter value to search for: ";
            cin >> value;
            obj.search(value);
            break;

        case 6:
            cout << "Displaying the list: ";
            obj.display();
            break;

        case 7:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

#include"Node.h"
#include<iostream>
using namespace std;

class DCLL {
protected:
    Node* head;
public:
    DCLL();
    virtual bool isEmpty() = 0;
    virtual void insertRecursive(Node* current, int position, int value) = 0;
    virtual void insertAtPosition(int value, int position) = 0;
    virtual void printListRecursive(Node* current) = 0;
    virtual void printList() = 0;
};

DCLL::DCLL() {
    head = nullptr;
}
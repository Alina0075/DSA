#include"CircularDoublyLinkedList.h"

class CircularDoublyLinkedList : public DCLL {
private:

    void insertRecursive(Node* current, int position, int value) {
        if (current == nullptr) {
            Node* newNode = new Node;
            newNode->data = value;
            if (head == nullptr) {
                head = newNode;
                head->next = head;
                head->prev = head;
            }
            else {
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
            }
        }
      
        else if (position == 1) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        else {
            insertRecursive(current->next, position - 1, value);
        }
    }

    void printListRecursive(Node* current) {
        if (current != nullptr) {
            cout << current->data << " ";
            if (current->next != head) {
                printListRecursive(current->next);
            }
        }
    }

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtPosition(int position, int value) {
        if (position <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        insertRecursive(head, position, value);
    }

    void printList() {
        if (!isEmpty()) {
            printListRecursive(head);
            cout << endl;
        }
        else {
            cout << "List is empty" << endl;
        }
    }
};
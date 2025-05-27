#include"MyDCLL.h"

int main() {
    CircularDoublyLinkedList cdll;

    cdll.insertAtPosition(1, 10);
    cdll.insertAtPosition(2, 20);
    cdll.insertAtPosition(3, 30);
    cdll.insertAtPosition(4, 40);

    cout << "Original list: ";
    cdll.printList();

    cdll.insertAtPosition(3, 25);

    cout << "List after inserting 25 at position 3: ";
    cdll.printList();

    return 0;
}
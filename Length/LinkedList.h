#include"Node.h"

class LinkedList
{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList();
	virtual void insertAtTail(int)=0;
	virtual void insertAtHead(int)=0;
	virtual void display()=0;
	virtual int deleteFromHead()=0;
	virtual int deleteFromTail()=0;
	virtual bool isEmpty()=0;
	virtual void insertSorted(int)=0;
	virtual int countnodes()=0;
};
LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}
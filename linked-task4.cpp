#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
#include"Node.h"

class LinkedList
{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList();
	virtual void insertAtTail(int)=0;
	virtual void insertAtHead(int) = 0;
	virtual void display() = 0;
	virtual int deleteFromHead() = 0;
	virtual int deleteFromTail() = 0;
	virtual bool isEmpty() = 0;
	virtual int FindKthToLast(int k) = 0;
};
LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}
#include "LinkedList.h"

class myLL :public LinkedList {
public:
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	int deleteFromHead();
	int deleteFromTail();
	bool isEmpty();
	int FindKthToLast(int k);
};

int myLL::FindKthToLast(int k) {
	int count = 0;
	if (tail == nullptr) {
		cout << "LL is empty" << endl;
	}
	else {
		Node* t = tail->next;
		while (1) {
			t = t->next;
			count++;
			if (t == tail->next)
				break;
		}
	}
	cout << "Total count is " << count << endl;
	if (k == count || k > count) {
		return -1;
	}
	else {
		int iterations = count - k;
		Node* temp = tail->next; 
		for (int i = 0; i < iterations; i++) {
			temp = temp->next;
		}
		return temp->data;
	}

}

int myLL::deleteFromHead()
{
	if (tail == nullptr)
		return NULL;

	else if (tail->next == tail)
	{
		int rV = tail->data;
		delete tail;
		tail = nullptr;
		return rV;
	}

	else
	{
		Node* t = tail->next;
		tail->next = t->next;
		int rV = t->data;
		delete t;
		t = nullptr;
		return rV;
	}
}


int myLL::deleteFromTail()
{
	if (tail == nullptr)
		return NULL;

	else if (tail->next == tail)
	{
		int rV = tail->data;
		delete tail;
		tail = nullptr;
		return rV;
	}

	else
	{
		Node* t = tail->next;
		while (true)
		{
			if (t->next == tail)
				break;

			t = t->next;
		}

		int rV = tail->data;
		t->next = tail->next;
		delete tail;
		tail = t;
		return rV;
	}
}

bool myLL::isEmpty()
{
	return (tail == nullptr);
}

void myLL::display()
{

	if (tail == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node* t = tail->next;
		while (true)
		{
			cout << t->data << "->";
			t = t->next;

			if (t == tail->next)
				break;
		}

	}

}

void myLL::insertAtHead(int value)
{
	Node* nn = nullptr;
	nn = new Node;
	nn->next = nullptr;
	nn->data = value;

	if (tail == nullptr)
	{
		tail = nn;
		tail->next = tail;
	}

	else
	{
		nn->next = tail->next;
		tail->next = nn;
	}

}


void myLL::insertAtTail(int value)
{
	Node* nn = nullptr;
	nn = new Node;
	nn->next = nullptr;
	nn->data = value;

	if (tail == nullptr)
	{
		tail = nn;
		tail->next = tail;
	}

	else
	{
		nn->next = tail->next;
		tail->next = nn;
		tail = nn;
	}

}
#include "myLL.h"
int main() {
	myLL obj;
	int kth;
	obj.insertAtTail(1);
	obj.insertAtTail(2);
	obj.insertAtTail(3);
	obj.insertAtTail(4);
	obj.insertAtTail(5);
	obj.insertAtTail(6);
	obj.insertAtTail(7);
	obj.insertAtTail(8);
	obj.insertAtTail(9);
	obj.insertAtTail(10);
	cout << "The linked list is: " << endl;
	obj.display();
	cout << endl;
	cout << "Please Enter the kth Element: " << endl;
	cin >> kth;
	cout << "The value of the kth to last element : " << obj.FindKthToLast(kth);

	return 0;
}

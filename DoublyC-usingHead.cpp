#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

#include"Node.h"

class LinkedList
{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList();
	virtual void insertusingHead(int) = 0;
	virtual void display() = 0;
	virtual void maximum() = 0;
	virtual void Secondmaximum() = 0;
	virtual void Sum() = 0;
	virtual void factorialofLinkList() = 0;
	virtual void Sort()=0;
	virtual void deleteven() = 0;
};
LinkedList::LinkedList() {
	head = nullptr;
}
#include"LinkedList.h"

class DCLL : public LinkedList {
public:
	void insertusingHead(int value);
	void display();
	void maximum();
	void factorialofLinkList();
	void Secondmaximum();
	void Sum();
	int fact(int value);
	void Sort();
	void deleteven();
};

void DCLL::insertusingHead(int value) {

	Node* nn = nullptr;
	nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	if (head == nullptr) {
		head = nn;
		head->next = head;
		head->prev = head;
	}
	else {
		nn->next=head;
		nn->prev = head->prev;
		head->prev->next = nn;
		head->prev = nn;
		head = nn;
	}
}

void DCLL::maximum() {
	if (head == nullptr) {
		cout << "LL is empty" << endl;
	}
	else
	{
		int maximum = head->data;
		Node* t = head;
		do
		{
			if (t->data > maximum) {
				maximum = t->data;
			}
			t = t->next;
		} while (t != head);
		cout << "The maximum value in linked list is: " << maximum << endl;
	}
}

int DCLL::fact(int value) {
	if (value > 0) {
		return value * fact(value - 1);
	}
	if (value == 0) {
		return 1;
	}
}

void DCLL::factorialofLinkList() {
	if (head == nullptr) {
		cout << "LL is empty" << endl;
	}
	else {
		Node* t = head;
		do
		{
			int value = t->data;
			cout << "The factorial is: " << fact(value) << endl;
			t = t->next;
		} while (t != head);
	}
}

void DCLL::Secondmaximum() {
	if (head == nullptr) {
		cout << "LL is empty" << endl;
	}
	else
	{
		int maximum = head->data;
		int Secondmaximum = INT_MIN;
		Node* t = head;
		do
		{
			if (t->data > maximum) {
				Secondmaximum = maximum;
				maximum = t->data;
			}
			else if (Secondmaximum < t->data && t->data != maximum)
			{
				Secondmaximum = t->data;
			}
				t = t->next;
		} while (t != head);
		cout << "The Second maximum value in linked list is: " << Secondmaximum << endl;
	}
}

void DCLL::Sum() {
	if (head == nullptr) {
		cout << "LL is empty" << endl;
	}
	else
	{
		int sum = 0;
		Node* t = head;
		do
		{
			sum = sum + t->data;
			t = t->next;
		} while (t != head);
		cout << "Sum of Linked list is: " << sum << endl;
	}
}


void DCLL::deleteven() {
	if (head == nullptr) {
		cout << "LL is empty" << endl;
		return;
	}

	Node* current = head;
	Node* temp = nullptr;

	do {
		if (current->data % 2 == 0) {
			temp = current;
			if (current->next == current) {
				delete head;
				head = nullptr;  
			}
			else {
				if (current == head) {
					head = current->next;  
				}
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			current = current->next;  
			delete temp;  
		}
		else {
			current = current->next;  
		}

	} while (current != head);  
}

void DCLL::display() {
	if (head == nullptr) {
		cout << "LL is empty" << endl;
	}
	else
	{
		Node* t = head;
		do
		{
			cout << t->data << "->";
			t = t->next;
		} while (t != head);
		//cout << t->data;
	}
}


void DCLL::Sort() {
	if (head == nullptr) {
		cout << "LL is empty" << endl;
	}
	else
	{
		Node* t = head;
		do {
			Node* t2 = t->next;
			do {
				if (t->data < t2->data) {
					int temp = t->data;
					t->data = t2->data;
					t2->data = temp;
				}
				t2 = t2->next;
			} while (t2->next != head);
			t = t->next;
		} while (t != head);
	}
}
#include"DCLL.h"

int main() {
	DCLL obj1;
	obj1.insertusingHead(4);
	obj1.insertusingHead(1);
	obj1.insertusingHead(8);
	obj1.insertusingHead(5);
	obj1.insertusingHead(6);
	cout << "Display: " << endl;
	obj1.display();
	cout << endl << endl;
	obj1.maximum();
	cout << endl;
	obj1.factorialofLinkList();
	cout << endl;
	obj1.Secondmaximum();
	cout << endl;
	obj1.Sum();
	cout << endl;
	obj1.Sort();
	cout << "After Sorting: " << endl;
	cout << endl;
	obj1.display();
	obj1.deleteven();
	cout << "After Deleting: " << endl;
	cout << endl;
	obj1.display();
	cout << endl;
	return 0;
}

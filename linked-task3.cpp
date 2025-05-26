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
	virtual void insertathead(int value)=0;
	virtual void insertattail(int value)=0;
	virtual void nodescount() = 0;
};

#include"linked.h"
class linkedlist:public linked {
public:
	linkedlist():linked(){}
	void insertathead(int value) {

		node* nn = nullptr;
		nn = new node;
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
	}

	void insertattail(int value) {

		node* nn = nullptr;
		nn = new node;
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

	void nodescount() {
		node* t = nullptr;
		t = head;
		while(t!=nullptr){
			count++;
			t = t->next;
		}
		cout << count << endl;
	}

	void display() {
		node* t = nullptr;
		t = head;
		while (t!=nullptr) {
			cout << t->data << "->";
			t = t->next;
		}
		cout << "NULL!" << endl;
	}
};

#include"linkedlist.h"
int main() {
	linkedlist list;
	int choice, value;

	while (true) {
		cout << "1. Insert at Head" << endl;
		cout << "2. Insert at Tail" << endl;
		cout << "3. Count Nodes" << endl;
		cout << "4. Display List" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to insert at head: ";
			cin >> value;
			list.insertathead(value);
			break;
		case 2:
			cout << "Enter value to insert at tail: ";
			cin >> value;
			list.insertattail(value);
			break;
		case 3:
			cout << "Number of nodes: ";
			list.nodescount();
			break;
		case 4:
			cout << "Linked List: ";
			list.display();
			break;
		case 5:
			cout << "Exiting program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}

	return 0;
}

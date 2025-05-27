#include"LinkedList.h"

class myLL: public LinkedList
{
public:
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	int deleteFromHead();
	int deleteFromTail();
	bool isEmpty();
	void insertSorted(int);
	void maximum();
};

// Task 4
void myLL::maximum() {
	int max = head->data;
	Node* temp = head;
	while (temp != nullptr) {
		if (max < temp->data) {
			max = temp->data;
		}
		temp = temp->next;
	}
	cout << "The maximum value in linked list is: " << max << endl;
}

void myLL::insertSorted(int value)
{
	if (head == nullptr && tail == nullptr) 
	{
		Node* nn = nullptr;
		nn = new Node;
		nn->next = nullptr;
		nn->data = value;
		head = nn;
		tail = nn;
	}

	else if (value <= head->data)
	{
		insertAtHead(value);
	}
	else if (value >= tail->data)
	{
		insertAtTail(value);
	}

	else
	{
		Node* nn = nullptr;
		nn = new Node;
		nn->next = nullptr;
		nn->data = value;

		Node* t = head;
		while (t!=nullptr)
		{
			if (t->data < value && t->next->data >= value) {
				nn->next = t->next;
				t->next = nn;
				break;
			}
			t = t->next;
		}
		
	}
}

bool myLL::isEmpty()
{
	return (head == nullptr && tail == nullptr);
}


int myLL::deleteFromTail()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}
	else if (head == tail)
	{
		int returningValue = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		int returningValue = tail->data;
		Node* t = head;
		while (t->next->next != nullptr)
		{
			t = t->next;
		}
		delete tail;

		tail = t;
		t->next = nullptr;
		return returningValue;
	}
}

int myLL::deleteFromHead()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}
	else if (head == tail)
	{
		int returningValue = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		int returningValue = head->data;
		Node* temp = head;
		head = head->next;

		delete temp;
		temp = nullptr;
		return returningValue;
	}
}


void myLL::display()
{
	if (head == nullptr && tail == nullptr)
		cout << "LL is empty" << endl;
	else
	{
		Node* t = head;
		while (true)
		{
			cout << t->data << endl;
			t = t->next;

			if (t == nullptr)
				break;
		}

	}
}

void myLL::insertAtTail(int value)
{
	Node* nn = nullptr;
	nn = new Node;
	nn->next = nullptr;
	nn->data = value;
	if (head == nullptr && tail == nullptr) 
	{
		head = nn;
		tail = nn;
	}
	else 
	{
		tail->next = nn;
		tail = nn;
	}
}


void myLL::insertAtHead(int value)
{
	Node* nn = nullptr;
	nn = new Node;
	nn->next = nullptr;
	nn->data = value;
	if (head == nullptr && tail == nullptr)
	{
		head = nn;
		tail = nn;
	}
	else
	{
		nn->next = head;
		head = nn;
	}

}


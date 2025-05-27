#include"LinkedList.h"

class myLL : public LinkedList
{
public:
	myLL() {}
	myLL(myLL& c);
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	int deleteFromHead();
	int deleteFromTail();
	bool isEmpty();
	void insertSorted(int);
	~myLL();
};

// copy constructor
myLL::myLL(myLL& c) {
	if (c.head == nullptr && c.tail == nullptr) { 
		head = nullptr;
		tail = nullptr;
	}
	else {
		head = new Node;
		head->data = c.head->data;
		head->next = nullptr;
		tail = head;

		Node* original = c.head->next;
		Node* copy = head;
		while (original != nullptr) {
			Node* newNode = new Node;
			newNode->data = original->data;
			newNode->next = nullptr;
			copy->next = newNode;
			copy = newNode;

			tail = copy;
			tail->next = nullptr;
		}
	}
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
		while (t != nullptr)
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

myLL::~myLL() {
	Node* del = head;
	while (del != nullptr) {
		Node* nextNode = del->next;
		delete del;
		del = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}
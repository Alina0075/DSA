#include<iostream>
#include<stack>
using namespace std;

class Stack {
protected:
	char* stack;
	int currentsize;
	int maxsize;
public:
	Stack(int s);
	virtual void push(char value) = 0;
	virtual char pop() = 0;
	virtual char top() = 0;
	virtual bool empty() = 0;
	virtual void evaluation(char st[]) = 0;
	~Stack();
};

Stack::Stack(int s) {
	stack = new char[s];
	currentsize = 0;
	maxsize = s;
}
Stack::~Stack() {
	delete stack;
	stack = nullptr;
}
#include"stack.h"
class MyStack :public Stack {
public:
	MyStack(int size);
	void push(char value);
	char pop();
	char top();
	bool empty();
	void evaluation(char st[]);
	void display();
};

MyStack::MyStack(int size) :Stack(size) {}

void MyStack::push(char value) {
	Stack::stack[Stack::currentsize] = value;
	Stack::currentsize++;
}

char MyStack::pop() {
	currentsize--;
	return stack[currentsize];
}

char MyStack::top() {
	return stack[currentsize - 1];
}

bool MyStack::empty() {
	return currentsize == 0;
}

void MyStack::evaluation(char st[]) {
	int value = 0;
	for (int i = 0; st[i] != '\0'; i++) {
		if (st[i] >= '0' && st[i] <= '9') {
			push(st[i]);
		}
		else if (st[i] == ' ') {
			continue;
		}
		else if (st[i] == '*') {
			char value1 = pop() - '0';
			char value2 = pop() - '0';
			value = value1 * value2;
			push(value + '0');
		}
		else if (st[i] == '+') {
			char value1 = pop() - '0';
			char value2 = pop() - '0';
			value = value1 + value2;
			push(value + '0');
		}
		else if (st[i] == '-') {
			char value1 = pop() - '0';
			char value2 = pop() - '0';
			value = value2 - value1;
			push(value + '0');
		}
		else if (st[i] == '/') {
			char value1 = pop() - '0';
			char value2 = pop() - '0';
			if (value1 != 0) {
				value = value2 / value1;
				push(value + '0');
			}
			else {
				cout << "Error: Division by zero!" << endl;
				return;
			}
		}
	}

	int finalvalue = pop() - '0';

	cout << "Value is: " << finalvalue;
	cout << endl;
}

void MyStack::display() {
	for (int i = 0; i < currentsize; i++) {
		cout << stack[i];
	}
}
#include "mystack.h"
int main() {
	int j = 0;
	char a;
	const int max = 100;
	char stack[max] = "6 3 + 2 *";
	MyStack obj1(max);
	obj1.evaluation(stack);
	return 0;
}

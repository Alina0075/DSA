#include<iostream>
#include<stack>
#include<cstring>
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
	virtual void infixToPostfix(char st[]) = 0;
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


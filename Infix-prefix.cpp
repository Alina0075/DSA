#include <iostream>
#include <string>
using namespace std;
template <class t>
class stack {
protected:
	t* Stack;
	int currentsize;
	int maxsize;
public:
	stack() {} 
	stack(int s) { 
		currentsize = 0;
		maxsize = s;
		Stack = new t[maxsize];
	}
	~stack() {
		delete[]Stack;
		Stack = nullptr;
	}
	virtual void push(t value) = 0;
	virtual t pop() = 0;
	virtual bool full() = 0;
	virtual bool empty() = 0;
};
#include "stack.h"
#include <string>
template <class t>
class mystack :public stack<t> {
public:
	mystack() {}
	mystack(int s) :stack<t>(s) {}
	void push(t v);
	t pop();
	t top();
	bool full();
	bool empty();
	void display();
};

template<typename t>
void mystack<t>::push(t v) {
	if (full()) { cout << "Stack is full"; }
	else {
		stack<t>::Stack[stack<t>::currentsize++] = v;
	}
}

template<typename t>
t mystack<t>::pop() {
	if (empty()) {
		cout << "Stack is Empty";
	}
	else {
		return  stack<t>::Stack[--stack<t>::currentsize];
	}
}

template<typename t>
bool mystack<t>::full() {
	return  stack<t>::currentsize == stack<t>::maxsize;
}

template<typename t>
bool mystack<t>::empty() {
	return  stack<t>::currentsize == 0;
}

template<typename t>
t mystack<t>::top() {
	return  stack<t>::Stack[stack<t>::currentsize - 1];
}

template<typename t>
void mystack<t>:: display() {

	for (int i = 0; i < stack<t>::currentsize; i++) {
		cout << "index " << i << ") " << stack<t>::Stack[i] << " " << endl;
	}
}
#include "mystack.h"
using namespace std;

string reverse(string& stack1, int s) {
	string stack2(s, '\0');

	for (int i = 0; i < s; i++) {
		stack2[i] = stack1[s - i - 1];

		if (stack2[i] == '(') {
			stack2[i] = ')';
		}

		else if (stack2[i] == ')') {
			stack2[i] = '(';
		}
	}
	return stack2;
}

string InfixToPrefix(string stack, int size) {
	string result;
	mystack<char>obj1(size);
	for (int i = 0; i < size; i++) {
		if (stack[i] == '(') {
			obj1.push(stack[i]);
		}
		if (stack[i] >= 'a' && stack[i] <= 'z'|| stack[i] >= 'A' && stack[i] <= 'Z') {
			result = result + stack[i];
		}
		if (stack[i] == '+' || stack[i] == '-' || stack[i] == '/' || stack[i] == '*' || stack[i] == '^') {
			obj1.push(stack[i]);
		}
		if (stack[i] == ')') {
			result =result+ obj1.pop();
			obj1.pop();
		}
	}
	while (!obj1.empty()) {
		result = result+ obj1.pop();
	}
	return result;
}
int main() {
	string Infix = "(((a+b)*(c+d))/(a-b))";
	int length = Infix.length();
	cout << "Infix: " << Infix << endl << endl;

	string reversed = reverse(Infix, length);
	string prefix = InfixToPrefix(reversed, length);

	string final_prefix = reverse(prefix, prefix.length());
	cout << "Prefix: " << final_prefix << endl << endl;

	return 0;
}

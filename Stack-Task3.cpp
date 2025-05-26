#include <iostream>
#include <string>
using namespace std;

template<typename T>
class abstractstack {
protected:
    T* stack;
    int maxsize;
    int currentsize;
public:
    abstractstack(int size) {
        maxsize = size;
        currentsize = 0;
        stack = new T[size];
    }
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual T top() const = 0;
    virtual ~abstractstack() { delete[] stack; }
};
#include"abstractstack.h"

template<typename T>
class myStack : public abstractstack<T> {
public:
    myStack(int size) : abstractstack<T>(size) {}

    void push(T value) override {
        if (abstractstack<T>::currentsize < abstractstack<T>::maxsize) {
            abstractstack<T>::stack[abstractstack<T>::currentsize++] = value;
        }
        else {
            cout << "Stack is full." << endl;
        }
    }

    T pop() override {
        if (abstractstack<T>::currentsize > 0) {
            return abstractstack<T>::stack[--abstractstack<T>::currentsize];
        }
        else {
            cout << "Stack is empty." << endl;
            return T();
        }
    }

    bool isEmpty() const override {
        return abstractstack<T>::currentsize == 0;
    }

    T top() const override {
        if (abstractstack<T>::currentsize > 0) {
            return abstractstack<T>::stack[abstractstack<T>::currentsize - 1];
        }
        else {
            cout << "Stack is empty." << endl;
            return T();
        }
    }
};

#include"MyStack.h"

bool bracket_check(const string& expression) {
    myStack<char> stack(expression.size());
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty()) return false;
            char topBracket = stack.top();
            if ((ch == ')' && topBracket == '(') ||
                (ch == ']' && topBracket == '[') ||
                (ch == '}' && topBracket == '{')) {
                stack.pop();
            }
            else {
                return false;
            }
        }
    }
    return stack.isEmpty();
}
int main() {
    int choice;
    string expression;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter an expression\n";
        cout << "2. Check if the expression is balanced\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter an expression with brackets to check: ";
            cin >> expression;
            break;
        }
        case 2: {
            if (expression.empty()) {
                cout << "Please enter an expression first (Option 1)." << endl;
            }
            else {
                if (bracket_check(expression)) {
                    cout << "The expression is balanced." << endl;
                }
                else {
                    cout << "The expression is not balanced." << endl;
                }
            }
            break;
        }
        case 0: {
            cout << "Exiting program." << endl;
            break;
        }
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

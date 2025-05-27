#include"stack.h"
class MyStack :public Stack {
public:
    MyStack(int size);
    void push(char value);
    char pop();
    char top();
    bool empty();
    void infixToPostfix(char st[]);
};

MyStack::MyStack(int size) :Stack(size) {}

void MyStack::push(char value) {
    Stack::stack[Stack::currentsize] = value;
    Stack::currentsize++;
}

char MyStack::pop() {
    Stack::currentsize--;
    return stack[Stack::currentsize];
}

char MyStack::top() {
    return Stack::stack[Stack::currentsize - 1];
}

bool MyStack::empty() {
    return Stack::currentsize == 0;
}

void MyStack::infixToPostfix(char st[]) {
    char stack2[100];
    char store[10];
    int k = 0, j = 0;
    int temp = 0;

    for (int i = 0; st[i] != '\0'; i++) {
        if (st[i] == '(') {
            push(st[i]);
        }
        else if (st[i] >= '0' && st[i] <= '9') {
            temp = st[i] - '0';
            i++;
            while (st[i] >= '0' && st[i] <= '9') {
                temp = temp * 10 + (st[i] - '0');
                i++;
            }
            i--;
            k = 0;
            while (temp > 0) {
                store[k++] = (temp % 10) + '0';
                temp = temp / 10;
            }

            for (int m = k - 1; m >= 0; m--) {
                stack2[j++] = store[m];
            }
            stack2[j++] = ' ';
        }
        else if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/') {
            push(st[i]);
        }
        else if (st[i] == ')') {
            while (!empty() && top() != '(') {
                stack2[j++] = pop();
                stack2[j++] = ' ';
            }
            pop();
        }
    }

    while (!empty()) {
        char v4 = pop();
        if (v4 != '(') {
            stack2[j++] = v4;
            stack2[j++] = ' ';
        }
    }
    stack2[j] = '\0';

    cout << "Postfix Expression: " << stack2 << endl;
}


#include"MyStack.h"
int main() {
	
	const int max = 100;
	char stack[max] = "((( 12 + 13 ) * ( 20 - 30 )) / ( 811 - 99 ))";
	MyStack obj1(max);
	cout << "Infix Expression:";
	cout << stack << endl;
	cout << endl;
	obj1.infixToPostfix(stack);
	return 0;
}
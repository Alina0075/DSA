#include"myLL.h"

int main() {
	myLL obj1;
	obj1.insertAtTail(1);
	obj1.insertAtTail(3);
	obj1.insertAtTail(7);
	obj1.insertAtTail(5);
	obj1.insertAtTail(14);
	cout << "The values of linked list are: " << endl;
	obj1.display();
	obj1.midvalue();
	return 0;
}

#include"myLL.h"

int main() {
	myLL obj1;
	obj1.insertAtTail(1);
	obj1.insertAtTail(52);
	obj1.insertAtTail(1000);
	obj1.insertAtTail(65);
	cout << "The values of linked list are: " << endl;
	obj1.display();
	obj1.maximum();
	return 0;
}

#include"myLL.h"

int main() {
	myLL obj1;
	obj1.insertAtTail(1);
	obj1.insertAtTail(2);
	obj1.insertAtTail(2);
	obj1.insertAtTail(1);
	cout << "The values of linked list are: " << endl;
	obj1.display();
	obj1.plaindrome();
	return 0;
}

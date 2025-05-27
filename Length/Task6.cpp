#include"myLL.h"

int main() {
	myLL obj1;
	obj1.insertAtTail(1);
	obj1.insertAtTail(52);
	obj1.insertAtTail(30);
	obj1.insertAtTail(75);
	obj1.insertAtTail(20);
	obj1.insertAtTail(64);
	cout << "The values of linked list are: " << endl;
	obj1.display();
	int count = obj1.countnodes();
	cout << "The Number of Nodes(length/size) of linked list are: " << count << endl;
	return 0;
}

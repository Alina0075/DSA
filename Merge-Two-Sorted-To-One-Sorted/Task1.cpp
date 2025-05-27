#include"myLL.h"

void mergeinglinkedlist(myLL& obj2, myLL& obj3) {
	while (!obj3.isEmpty()) {
		int value = obj3.deleteFromTail();
		obj2.insertSorted(value);
	}
}

int main() {
	myLL obj1;
	obj1.insertSorted(2);
	obj1.insertSorted(78);
	obj1.insertSorted(4);
	obj1.insertSorted(45);
	obj1.insertSorted(23);
	cout << "The first Sorted Linked List is: " << endl;
	obj1.display();

	myLL obj2;
	obj2.insertSorted(0);
	obj2.insertSorted(9);
	obj2.insertSorted(75);
	obj2.insertSorted(34);
	obj2.insertSorted(-1);
	cout << "The second Sorted Linked List is: " << endl;
	obj2.display();

	mergeinglinkedlist(obj1, obj2);
	cout << "The Sorted Merged Linked List is: " << endl;
	obj1.display();
	return 0;
}

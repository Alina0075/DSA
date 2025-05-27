#include"Mytree.h"

int main() {
	mytree obj;
	obj.insert(50);
	obj.insert(30);
	obj.insert(70);
	obj.insert(20);
	obj.insert(40);
	obj.insert(60);
	obj.insert(80);

	cout << "Inserted Data is: ";
	obj.inorder();
	cout << endl;

	return 0;
}
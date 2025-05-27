#include "BST.h"

int main()
{
	BST obj;
	obj.insert(50);
	obj.insert(30);
	obj.insert(20);
	obj.insert(40);
	obj.insert(70);
	obj.insert(60);
	obj.insert(80);

	obj.inorder();
	cout << endl;
	BST obj2;
	obj2 = obj;
	cout << "Deep Copy: " << endl;
	obj2.inorder();

	return 0;
}


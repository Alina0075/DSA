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

	cout << "Searching for Node: " << endl;
	obj.search(40);
	cout << endl;
	cout << "Delete Node: " << endl;
	obj.deleteNode(20);
	cout << endl;
	obj.inorder();

	cout << endl;
	cout << "Tree Height is: " << obj.TreeHeight() << endl;

	return 0;
}


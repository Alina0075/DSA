#include "BST.h"

int main()
{
	BST obj;
	obj.insert(6);
	obj.insert(3);
	obj.insert(4);
	obj.insert(1);
	obj.insert(8);
	obj.insert(7);
	obj.insert(9);
	cout << "The Tree values are: " << endl;
	obj.inorder();

	obj.MedianOfBST();

	return 0;
}


#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*);
	int median();
	void storing(Node* r, int array[], int& size);
	void countRec(Node* p, int& count);
public:
	void insert(int);
	void inorder();
	void MedianOfBST();
	int countNodes();
};

int BST::median() {
	int n = countNodes();
	if (n % 2 == 0) {
		return ((n / 2) + ((n / 2) + 1)) / 2;
	}
	else {
		return (n + 1) / 2;
	}
}

void BST::MedianOfBST() {

	const int size = countNodes();
	int* array = new int[size];
	int sizeIndex = 0;

	storing(root, array, sizeIndex);

	int mediannumber = median();
	cout << "So, here the Median will be: " << array[mediannumber - 1] << endl;
	delete[] array;

}

void BST::storing(Node* r, int array[], int& size) {
	if (r == nullptr) {
		return;
	}
	else {
		storing(r->leftChild, array, size);
		array[size++] = r->data;
		storing(r->rightChild, array, size);
	}
}

void BST::countRec(Node* p, int& count)
{
	if (p != nullptr)
	{
		countRec(p->leftChild, count);
		count++;
		countRec(p->rightChild, count);
	}
}

int BST::countNodes()
{
	int c = 0;
	if (root != nullptr)
		countRec(root, c);

	else
		cout << "Tree is empty" << endl;

	return c;
}

void BST::INORDER(Node* p)
{
	if (p != nullptr)
	{
		INORDER(p->leftChild);
		cout << p->data << " ";
		INORDER(p->rightChild);
	}
}

void BST::inorder()
{
	if (root != nullptr) {
		INORDER(root);
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

void BST::insert(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->leftChild = nullptr;
	nn->rightChild = nullptr;

	if (root == nullptr) {
		root = nn;
	}
	else
	{
		Node* t = root;
		while (1)
		{
			if (value < t->data)
			{
				if (t->leftChild == nullptr)
				{
					t->leftChild = nn;
					break;
				}
				else
					t = t->leftChild;
			}
			else 
			{
				if (t->rightChild == nullptr) 
				{
					t->rightChild = nn;
					break;
				}
				else
					t = t->rightChild;
			}
		}
	}
}
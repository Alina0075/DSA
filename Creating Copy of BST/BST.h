#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*);
public:
	void insert(int);
	void inorder();
};


void BST::INORDER(Node* p)
{
	if (p != nullptr)
	{
		INORDER(p->leftChild);
		cout << p->data << endl;
		INORDER(p->rightChild);
	}
}

void BST::inorder()
{
	if (root != nullptr)
		INORDER(root);

	else
		cout << "Tree is empty" << endl;
}

void BST::insert(int value)
{
	Node* nn = new Node(value);

	if (root == nullptr)
		root = nn;

	else
	{
		Node* t = root;
		while (1)
		{
			if (value < t->data) //left side case
			{
				if (t->leftChild == nullptr) //add value here
				{
					t->leftChild = nn;
					break;
				}

				else
					t = t->leftChild;
			}

			else //right child case
			{
				if (t->rightChild == nullptr) //add value here
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
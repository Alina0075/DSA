#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*);
	bool searchrecursive(Node* r, int value);
	int treeheightRec(Node* r);
	//int treeheightRec2(Node* r);
    //int max(int x, int y);
public:
	void insert(int);
	void inorder();
	bool deleteNode(int);
	void search(int value);
	int TreeHeight();
};

/* Other method
int BST::treeheightRec2(Node* r) {
	if (r == nullptr) {
		return 0;
	}
	else {
		return 1 + max(treeheightRec2(r->leftChild), treeheightRec2(r->rightChild));
	}
}
int BST::max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}*/

int BST::treeheightRec(Node* r) {
	if (r == nullptr) {
		return 0;
	}
	else {
		int leftheight = treeheightRec(r->leftChild);
		int rightheight = treeheightRec(r->rightChild);

		if (leftheight > rightheight) {
			return 1 + leftheight;
		}
		else {
			return 1 + rightheight;
		}
	}
}

int BST :: TreeHeight() {
	return treeheightRec(root);
}

bool BST::searchrecursive(Node* r, int value) {
	if (r == nullptr) {
		return false;
	}
	if (r->data == value) {
		return true;
	}
	return searchrecursive(r->leftChild, value) || searchrecursive(r->rightChild, value);
}

void BST::search(int value) {
	if (searchrecursive(root, value)) {
		cout << "Number found: " << value;
	}
	else {
		cout << "Number not found!";
	}
}


bool BST::deleteNode(int value)
{
	if (root == nullptr)
		return false;

	else if (root->leftChild == nullptr && root->rightChild == nullptr) 
	{
		if (root->data == value)
		{
			delete root;
			root = nullptr;
			return true;
		}

		else
			return false;
	}
	else
	{
		Node* p = root;
		Node* c = root;

		while (1)
		{
			if (c == nullptr)
				return false;

			if (c->data == value)
			{
				break;
			}
			if (value < c->data)
			{
				p = c;
				c = c->leftChild;
			}
			else
			{
				p = c;
				c = c->rightChild;
			}
		}

		if (c->leftChild != nullptr && c->rightChild != nullptr)
		{
			Node* t = c;
			p = c;
			c = c->rightChild;

			while (1)
			{
				if (c->leftChild == nullptr)
				{
					t->data = c->data;
					value = c->data;
					break;
				}
				else
				{
					p = c;
					c = c->leftChild;
				}
			}
		}

		//  3 if root right child is absent
		if (c->rightChild == nullptr && c->leftChild != nullptr) {
			root = c->leftChild;
			delete c;
			c = nullptr;
			return true;
		}

		// 4 if root left child is absent
		if (c->leftChild == nullptr && c->rightChild != nullptr) {
			root = c->rightChild;
			delete c;
			c = nullptr;
			return true;
		}

		if (c->leftChild == nullptr && c->rightChild == nullptr)
		{
			if (c->data < p->data) // left child of parent
			{
				delete c;
				c = nullptr;
				p->leftChild = nullptr;
			}

			else //right child of parent
			{
				delete c;
				c = nullptr;
				p->rightChild = nullptr;
			}

			return true;
		}
	
		else if (c->leftChild != nullptr && c->rightChild == nullptr)
		{
			if (c->data < p->data) //leftChild of parent
			{
				p->leftChild = c->leftChild;
				delete c;
				c = nullptr;
				return true;
			}

			else //right child of parent
			{
				p->rightChild = c->leftChild;
				delete c;
				c = nullptr;
				return true;
			}
		}

		else if (c->leftChild == nullptr && c->rightChild != nullptr)
		{
			if (c->data < p->data) //leftChild of parent
			{
				p->leftChild = c->rightChild;
				delete c;
				c = nullptr;
				return true;
			}

			else //right child of parent
			{
				p->rightChild = c->rightChild;
				delete c;
				c = nullptr;
				return true;
			}

		}
	}

}

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
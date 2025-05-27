#include"Tree.h"

class mytree :public tree {
private:
	
	void inorderRecursive(Node* r);
	Node* insertrecusive(Node* r, int value);
public:
	void insert(int value);
	void inorder();
};

void mytree::inorderRecursive(Node* r) {
	if (r != nullptr) {
		inorderRecursive(r->leftchild);
		cout << r->data << " ";
		inorderRecursive(r->rightchild);
	}
}

Node* mytree:: insertrecusive(Node* r, int value) {
	if (r == nullptr) {
		return new Node(value);
	}
	if (value < r->data) {
		r->leftchild = insertrecusive(r->leftchild, value);
	}
	if (value > r->data) {
		r->rightchild = insertrecusive(r->rightchild, value);
	}
	return r;
}

void mytree::insert(int value) {
	root = insertrecusive(root, value);
}


void mytree::inorder() {
	if (root != nullptr) {
		inorderRecursive(root);
	}
	else {
		cout << "Tree is empty!";
	}
}

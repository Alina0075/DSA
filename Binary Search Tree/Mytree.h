#include"Tree.h"

class mytree :public tree {
private:
	void inorderRecursive(Node* r) {
		if (r != nullptr) {
			inorderRecursive(r->leftchild);
			cout << r->data << " ";
			inorderRecursive(r->rightchild);
		}
	}

public:
	void insert(int value) {
		Node* nn = new Node;
		nn->data = value;
		nn->leftchild = nullptr;
		nn->rightchild = nullptr;

		if (root == nullptr) {
			root = nn;
		}
		else {
			Node* t = root;
			while (1) {
				if (value < t->data) {
					if (t->leftchild == nullptr) {
						t->leftchild = nn;
						break;
					}
					else {
						t = t->leftchild;
					}
				}
				else {
					if (t->rightchild == nullptr) {
						t->rightchild = nn;
						break;
					}
					else {
						t = t->rightchild;
					}
				}
			}

		}
	}

	void inorder() {
		if (root != nullptr) {
			inorderRecursive(root);
		}
		else {
			cout << "Tree is empty!";
		}
	}

};
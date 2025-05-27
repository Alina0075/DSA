#include<iostream>
#include"Node.h"
using namespace std;

class tree {
protected:
	Node* root;
public:
	tree();
	virtual void insert(int value) = 0;
	virtual void inorder() = 0;
};

tree::tree() {
	root = nullptr;
}
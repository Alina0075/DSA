#include "Node.h"
#include <iostream>
using namespace std;

class Tree
{
protected:
	Node* root;
public:
	Tree();
	virtual void insert(int) = 0;
	virtual void inorder() = 0;

};

Tree::Tree()
{
	root = nullptr;
}
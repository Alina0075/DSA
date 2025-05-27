struct Node {
	int data;
	Node* leftchild;
	Node* rightchild;

	Node(int value) {
		data = value;
		leftchild = nullptr;
		rightchild = nullptr;
	}
};

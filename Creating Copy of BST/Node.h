struct Node
{
	
	int data;
	Node* leftChild;
	Node* rightChild;
	Node(int da) {
		data = da;
		leftChild = nullptr;
		rightChild = nullptr;
	}

    Node(const Node& copy) {
        data = copy.data;
        leftChild = deepCopy(copy.leftChild);  
        rightChild = deepCopy(copy.rightChild); 
    }

private:
  
    Node* deepCopy(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
       
        Node* newNode = new Node(node->data);
        newNode->leftChild = deepCopy(node->leftChild);
        newNode->rightChild = deepCopy(node->rightChild);
        return newNode;
    }
};
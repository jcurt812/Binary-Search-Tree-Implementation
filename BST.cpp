#include "BST.h"

using namespace std;

BST::~BST() {
	clear();
}

int BST::leftHeight(Node *startNode) {
	int heightCount = 0;
	while (startNode != NULL) {
		startNode = startNode->leftChild;
		++heightCount;
	}
	return heightCount;
}

int BST::rightHeight(Node *startNode) {
	int rightCount = 0;
	while (startNode != NULL) {
		startNode = startNode->rightChild;
		++rightCount;
	}
	return rightCount;
}

//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
NodeInterface * BST::getRootNode() const {
	return root;
}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
bool BST::add(int data) {
	return insert(data, this->root);
}

bool BST::insert(int data, Node* &yeetNode) {
	if (yeetNode == NULL) {
		yeetNode = new Node(data);
		nodeCount++;
		return true;
	}
	if (yeetNode->value == data) {
		return false;
	}
	if (yeetNode->value < data) {
		return insert(data, yeetNode->rightChild);
	}
	if (yeetNode->value > data) {
		return insert(data, yeetNode->leftChild);
	}
}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
bool BST::remove(int data) {
	return kookSlam(data, this->root);
}

bool BST::kookSlam (int data, Node* &deleteNode) {
	if (deleteNode == NULL) {
		return false;
	}
	else {
		if(data < deleteNode->value) {
			return kookSlam(data, deleteNode->leftChild);
		}
		else if (data > deleteNode->value) {
			return kookSlam(data, deleteNode->rightChild);
		}
		else {
			Node* oldRoot = deleteNode;
			if (deleteNode->leftChild == NULL) {
				deleteNode = deleteNode->rightChild;
				delete oldRoot;
				nodeCount--;
			}
			else if (deleteNode->rightChild == NULL) {
				deleteNode = deleteNode->leftChild;
				delete oldRoot;
				nodeCount--;
			}
			else {
				replace(oldRoot, deleteNode->leftChild);
			}
			return true;
		}
	}
}

void BST::replace(Node*& oldRoot, Node*& localRoot) {
	if (localRoot->rightChild != NULL) {
		replace(oldRoot, localRoot->rightChild);
	}
	else {
		oldRoot->value = localRoot->value;
		kookSlam(localRoot->value, oldRoot->leftChild); 
	}
}

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
void BST::clear() {
	while (root != NULL) {
		kookSlam(root->value, root);
	}
}
#include "Node.h"
#include "BST.h"
#include <iostream>

using namespace std;

/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
int Node::getData() const {
	return value;
}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
NodeInterface * Node::getLeftChild() const {
	//if (nodeCount < 2) {
	//	return NULL;
	//}
	return leftChild;
}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
NodeInterface * Node::getRightChild() const {
	//if (nodeCount < 2) {
	//	return NULL;
	//}
	return rightChild;
}
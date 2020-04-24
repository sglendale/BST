#include <iostream>
#include "node.h"

//Default Constructor definition
node::node() {

	data = 0;
	leftChild = NULL;
	rightChild = NULL;

}

//Note that the default constructor may also be written as:
// node::node : data(0), leftChild(NULL), rightChild(NULL){} 

//Parameterized Constructor definition
node::node(int value) {

	data = value;
	leftChild = rightChild = NULL;
}

//Insert function definition
node* node::insert(node* root, int value) {

	//Insert the first node, if root is NULL.
	if (!root)
	{
		//Explicit call to parameterized constructor. 
		return new node(value);
	}

	//Insert data
	if (value > root->data)
	{
		//Insert right node data if the 'value' to be inserted is greater than (the current/relative) 'root' node data
		//At the next call to insert, if root->rightChild is NULL, that is, the above check of if(!root) returns true, a new node with 
		//two NULL children is created with an explicit call to the Parameterized Constructor
		root->rightChild = insert(root->rightChild, value);
	
	}
	else 
	{
		//Insert left node data if the value to be inserted is less than or equal to the (current/relative) 'root' node data.
		root->leftChild = insert(root->leftChild, value);
	
	}

	return root; 

}

//Search function definition
node* node::search(node* root, int key) {


	//Possibilities
	// 1) There are no nodes left to search; that is, the key is not in the tree, OR the key is a leaf node, OR there 
	// exist no nodes in the tree left to search.
	if (root->leftChild == NULL && root->rightChild == NULL)
		return root;

	// 2) The key is greater than root's key*/
	else if (root->data < key)
		return search(root->rightChild, key);

	// 3) The key is less than root's key*/
	else 
		return search(root->leftChild, key);

}

//Acessor function definition
int node::getData() {

	return data;

}

// In-order uses a stack, and is a Depth-first search. 
// 1.) Traverse left until there is no left. 
// 2.) Print ("Visit") this leftmost node which has no left children remaining.
// 3.) Visit the rightChild of the most recently printed node. Repeat step 1. 
// Check out this video for an awesome explanation of Inorder Traversal: https://www.youtube.com/watch?v=5dySuyZf9Qg

//Inorder traversal definition
void node::inorder(node* root) {

	if (root->leftChild != NULL)
		inorder(root->leftChild);

	std::cout << root->data << std::endl;

	if (root->rightChild != NULL)
		inorder(root->rightChild);

}

//Preorder, like Inorder, uses a stack implementation and is also a Depth-first search.
// 1.) Visit node
// 2.) Traverse left
// 3.) Traverse right
// Check out the awesome explanation in this video: https://www.youtube.com/watch?v=1WxLM2hwL-U

//Preorder traversal definition
void node::preorder(node* root) {

	//Note that this null check returns control to the previous recursive call and continues executing where it last left off. 
	//BEAUTIFUL!
	if (root == NULL)
		return;

	std::cout <<root->data << std::endl;
	preorder(root->leftChild);
	preorder(root->rightChild);


}
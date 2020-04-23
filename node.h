#pragma once
#include <stddef.h>
/* Note: initializing a  struct must be completed by enclosing the desired values for the struct members in "{}" in the order in which they
are declared in the struct*/


/* Binary Search Tree */
/* A Binary Search Tree is a node-based binary tree data strucutre which has the following properties: */
/* -  the left subtree of a node contains only nodes with keys less than or equal to the node's key*/
/* - the right subtree of a node contains only nodes with keys greater than the node's key*/
/* - the left and right subtree each must also be a BST*/
/* The basic  operations of a Tree are: */
/* - insert*/ 
/* - search* /
/* - pre-order traversal*/
/* - in-order traversal*/
/* - post-order traversal*/

class node {

/*Note that the private declaration is optional. Anything before public is assumed private, 
and can only be accessed through member functions.*/

private:
	int data;
	node* leftChild;
	node* rightChild;

/*Note on member functions: you should make them private only if you expect to use that member function as a 
helping function in the definition of member functions; for example a function called "check" to check the validity of
a public member function's values, should be private, because it is only used within that function and is not meant for 
direct access.*/

public:

	//Default Constructor declaration
	node();

	//Parameterized constructor declaration
	node(int);

	//Insert function
	node* insert(node*, int);

	int getData();

	//Search function
	node* search(node*, int);

	//Inorder traversal declaration
	void inorder(node*);

	void preorder(node*);

	//Preorder traversal declaration

	//Postorder traversal declaration


};

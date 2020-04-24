/* Demo of BST functions */
/* By Sharon Glendale */

#include<iostream>
#include <string>
#include "node.h"
using namespace std;

int main() {

	node bst;
	node* root = NULL; 

	cout << "Welcome to the BST Demo." << endl << "To start, let us insert nodes with the following values specified:" << endl;

	//You may edit these values before building your program, or even make it more interactive by prompting the user to 
	//to build the tree with input they provide. 
	root = bst.insert(root, 50);
	cout << "Inserting 50."<< endl;
	bst.insert(root, 30);
	cout << "Inserting 30." << endl;
	bst.insert(root, 20);
	cout << "Inserting 20." << endl;
	bst.insert(root, 40); 
	cout << "Inserting 40." << endl;
	bst.insert(root, 70);
	cout << "Inserting 70." << endl;
	bst.insert(root, 60); 
	cout << "Inserting 60." << endl;
	bst.insert(root, 80);
	cout << "Inserting 80." << endl;
	cout << "Tree build complete." << endl;

	cout << "Now lets do an In-order tree traversal!" << endl;
	bst.inorder(root);
	cout << "Second, lets do a Pre-order tree traversal!" << endl;
	bst.preorder(root);
	cout << "Finally, let us do a Post-order traversal!" << endl;
	bst.postorder(root);

	int tempKey = 0;
	string input = "";

	cout << "We may now perform a search." << endl
		<< "If the number is in our tree the search will return true." << endl;

	while (input != "exit")
	{
		cout << "Please enter a non-zero number you would like to search for:";
		cin >> tempKey;


		node* IsInTree = bst.search(root, tempKey);

		if (IsInTree != NULL && IsInTree->getData() == tempKey)
			cout << tempKey << " is in the tree! " << endl << IsInTree->getData() << " was returned from your search." << endl;
		else
			cout << tempKey << " is not in the tree." << endl;

		cout << "If you would like exit the program, please type 'exit.' To continue, type anything else and press enter.";
		cin >> input;
	}

	cout << "You have reached the end of the Program. I am Iron Man. *Snaps*" << endl;

	return 0;

}





/* Demo of BST functions */
/* By Sharon Glendale */

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "node.h"
using namespace std;

//Utility function prototypes

//Returns the equivalent string input in all lower case.
string toLowerConversion(string); 

//Verifies that user input is a valid option.
bool isValid(string);

//Validates that all characters in a string are digits.
bool isNumber(string);

//Returns Integer equivalent to concatenated chars in string.
int stringToInt(string);


int main() {

	node bst;
	node* root = NULL; 

	cout << endl << " ############################## Welcome to the BST Demo ############################## " << endl << endl
		<< " To start, we must first build a tree. Let us insert nodes with the following values:" << endl << endl;

	//You may edit these values before building your program, or even make it more interactive by prompting the user to 
	//to build the tree with input they provide. 
	root = bst.insert(root, 50);
	cout << " Inserting 50."<< endl;
	bst.insert(root, 30);
	cout << " Inserting 30." << endl;
	bst.insert(root, 20);
	cout << " Inserting 20." << endl;
	bst.insert(root, 40); 
	cout << " Inserting 40." << endl;
	bst.insert(root, 70);
	cout << " Inserting 70." << endl;
	bst.insert(root, 60); 
	cout << " Inserting 60." << endl;
	bst.insert(root, 80);
	cout << " Inserting 80." << endl << endl;
	cout << " Tree build complete!" << endl << endl;


	string input = "";


	do {
		do
		{
			cout << " This program can perform the following actions: " << endl << endl;
			cout << " 1) In-order Traversal" << endl;
			cout << " 2) Pre-order Traversal" << endl;
			cout << " 3) Post-order Traversal" << endl;
			cout << " 4) Search" << endl << endl;
			cout << " Please type a numeric option and press enter, or type exit and press enter to quit: ";
			cin >> input;

			if (!isValid(input))
				cout << endl << " You have entered invalid input. Please review the menu below." << endl << endl;

		} while (!isValid(input));


		if (input == "1") {

			cout << endl << " Here is an In-order tree traversal: ";
			bst.inorder(root);
			cout << endl;
		}
		else if (input == "2") {

			cout << " Here is a Pre-order tree traversal: ";
			bst.preorder(root);
			cout << endl;

		}
		else if (input == "3") {
			cout << " Here is a Post-order traversal: ";
			bst.postorder(root);
			cout << endl;
		}
		else if (input == "4") {

			int tempKey = 0;
			string nodeSearchParam = "";

			do {

				if (!isNumber(nodeSearchParam))
					cout << " That is not a valid integer. Try again." << endl;

				cout << " Please enter a non-zero number you would like to search for: ";
				cin >> nodeSearchParam;

				if (isNumber(nodeSearchParam)) {

					tempKey = stringToInt(nodeSearchParam);

					node* IsInTree = bst.search(root, tempKey);

					if (IsInTree != NULL && IsInTree->getData() == tempKey)
						cout << " " << tempKey << " is in the tree! " << endl << " " << IsInTree->getData() << " was returned from your search." << endl;
					else
						cout << " " << tempKey << " is not in the tree." << endl;
				}

			} while (!isNumber(nodeSearchParam));

		}
	} while (input != "exit");


	cout << endl << " You have reached the end of the Program. I am Iron Man. *Snaps*" << endl;
	return 0;

}

string toLowerConversion(string option) {


	for (int i = 0; i <= option.length(); i++) {
		option[i] = tolower(option[i]);
	}

	return option;

}

bool isValid(string option) {


	option = toLowerConversion(option);

	if (option != "exit" && option != "1" && option != "2" && option != "3" and option != "4")
		return false;
	else
		return true;


}
bool isNumber(string numberString)
{
	for (int i = 0; i < numberString.length(); i++)
		if (isdigit(numberString[i]) == false)
			return false;

	return true;
}
int stringToInt(string number) {


	stringstream converter(number);
	int tempInt = 0;
	converter >> tempInt;

	return tempInt;
}


#include "stdafx.h"
#include <string>
#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <fstream>

using namespace std;
void main()
{
	Node node;
	Tree tree;
	string file;
	int data;
	ifstream readFile;
	cout << "Mitchell Daw|CS 2420|Program #4" << endl;
	cout << "Please enter the name of the data file you would like to open:";
	//Have user hard code file in that they want to read
	cin >> file;
	//Open file using declared fstream
	readFile.open(file);
	//read through whole file and add data into AVL tree  until the end of the file is reached. 
	while (!readFile.eof()) {
		readFile >> data;
		tree.addChild(data);
	}
	//Print out data in tree Inorder recurssivley 
	cout << "--------- Recurssive Inorder Traversal------- " << endl;
	tree.inOrder(tree.getRoot());
	//Print out data in tree in Preorder Iratively
	cout <<"--------- Irative Preorder Traversal------- " << endl;
	tree.preOrderNonRecurssive(tree.getRoot());
	system("PAUSE");
}


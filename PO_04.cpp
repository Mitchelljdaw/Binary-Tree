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
	cout << "Please enter the name of the data file you would like to open:";
	cin >> file;
	readFile.open(file);
	while (!readFile.eof()) {
		readFile >> data;
		tree.addChild(data);

	}
	system("PAUSE");
}


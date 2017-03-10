#pragma once
#include "Node.h"
class Tree
{
private:
	Node* root;
public:
	Tree();
	Tree(Node* _root);
	void addChild(const int &_data);
	void addChildHelper(Node* current, const int &_data);
	~Tree();
};


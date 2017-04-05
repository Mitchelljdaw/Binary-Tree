#pragma once
#include "Node.h"
#include <stack>

class Tree
{
private:
	Node* root;
public:
	Tree();
	Tree(Node* _root);
	void addChild(const int &_data);
	void addChildHelper(Node* current, const int &_data);
	void inOrder(Node* _root);
	void preOrder(Node* _root);
	void preOrderNonRecurssive(Node* _root);
	void balfactor(Node * _root);
	void bfactor();
	int  height(Node *_root);
	int  max(int _left, int _right);
	void rebalance(Node* _root);
	Node* leftLeft(Node*& _root);
	Node* leftRight(Node*& _root);
	Node* rightRight(Node*& _root);
	Node* rightLeft(Node*& _root);
	Node* getRoot() {
		return root;
	}
	~Tree();
};


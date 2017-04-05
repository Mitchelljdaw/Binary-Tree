#include "stdafx.h"
#include <iostream>
#include <string>
#include "Node.h"
#include "Tree.h"
using namespace std;

Tree::Tree()
{

}

Tree::Tree(Node* _root) {
	root = _root;
}

void Tree::addChild(const int &_data) {
	if (root == nullptr) {
		Node* newRoot = new Node(nullptr, nullptr, _data);
		root = newRoot;
	}
	else {
		addChildHelper(root, _data);
	}
}

void Tree::addChildHelper(Node* _current,const int &_data) {
	if (_current->data == _data) {

	}
	 else if(_current->data > _data) {
		  if (_current->lChild == nullptr) {
			  Node* newLChild = new Node(nullptr, nullptr, _data);
			  _current->lChild = newLChild;
		  }
		  else {
			  addChildHelper(_current->lChild, _data);
		  }
	}
	  else {
		  if (_current->rChild == nullptr) {
			  Node* newRChild = new Node(nullptr, nullptr, _data);
			  _current->rChild = newRChild;

		  }
		  else {
			  addChildHelper(_current->rChild, _data);
		  }
	  }
	  bfactor();
	  rebalance(_current);
}

void Tree::rebalance(Node* _root) {
	if (_root->bf >= -1 && _root->bf <= 1) {
		cout << "No rotation needed" << endl;
	}
	else if (_root->bf < -1 || _root->bf > 1) {
		if (_root->bf < -1 && _root->rChild->bf >  0) {
			_root = rightLeft(_root);
			cout << "Rotation right left is needed" << endl;
		}
		else if (_root->bf < -1 && _root->rChild->bf < 0) {
			_root = rightRight(_root);
			cout << "Rotation right right is needed" << endl;
		}
		else if (_root->bf > 1 && _root->lChild->bf > 0) {
			_root = leftLeft(_root);
			cout << "Rotation left left is needed" << endl;
		}
		else if (_root->bf > 1 && _root->lChild->bf < 0) {
			_root = rightLeft(_root);
			cout << "Rotation right left is needed" << endl;
		}
	}
}


void Tree::inOrder(Node* _root) {
	if (_root == nullptr) {
		return;
	}
	else {
		inOrder(_root->lChild);
		cout << _root->data << endl;
		inOrder(_root->rChild);
	}
}

void Tree::preOrder(Node* _root) {
	if (_root == nullptr) {
		return;
	}
	else {
		cout << _root->data << endl;
		preOrder(_root->lChild);
		preOrder(_root->rChild);
	}
}

void Tree::preOrderNonRecurssive(Node* _root) {
	if (_root == nullptr) {
		return;
	}
	else {
		stack<Node*> stack;
		stack.push(_root);
		while (!stack.empty()) {
			struct Node *Node = stack.top();
			cout << Node->data << endl;
			stack.pop();
			if (Node->rChild) {
				stack.push(Node->rChild);
			}
			if (Node->lChild) {
				stack.push(Node->lChild);
			}
		}
	}

}

void Tree::balfactor(Node * _root) {
	if (_root != nullptr)
	{
		_root->bf = height(_root->lChild) - height(_root->rChild); 
		balfactor(_root->lChild); 
		balfactor(_root->rChild);
	}
}

void Tree::bfactor() {
	if (root != nullptr)
	{
		root->bf = height(root->lChild) - height(root->rChild); 
		balfactor(root->lChild); 
		balfactor(root->rChild);
	}
}

int Tree::height(Node *_root)
{
	if (_root == nullptr) return 0;
	if ((_root->lChild == nullptr) && (_root->rChild == nullptr))
		return 1;
	return 1 + max(height(_root->lChild), height(_root->rChild));
}


Node* Tree::leftRight(Node*& _root) {
	Node* temp = _root->lChild;
	_root->lChild = rightRight(temp);
	return leftLeft(_root);
}

Node* Tree::leftLeft(Node*& _root) {
	Node* temp = _root->lChild;
	_root->lChild = temp->rChild;
	temp->rChild = _root;
	return temp;
}

Node* Tree::rightRight(Node*& _root) {
	Node* temp = _root->rChild;
	_root->rChild = temp->lChild;
	temp->lChild = _root;
	return temp;
}

Node* Tree::rightLeft(Node*& _root) {
	Node* temp = _root->rChild;
	_root->rChild = leftLeft(temp);
	return rightRight(_root);
}
int Tree::max(int _left, int _right) {
	int m = _left; 
	if (_right > _left) {
		m = _right;
	}
	return m;
}
Tree::~Tree()
{
}

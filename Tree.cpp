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
	else if (root->data < _data && root->rChild == nullptr) {
		Node* newRChild = new Node(nullptr, nullptr, _data);
		root->rChild = newRChild;
	}
	else if (root->data > _data && root->lChild == nullptr) {
		Node* newLChild = new Node(nullptr, nullptr, _data);
		root->lChild = newLChild;
	}
	else {
		addChildHelper(root, _data);
	}
}

void Tree::addChildHelper(Node* _current,const int &_data) {
      if (_current->data > _data) {

		  if (_current->lChild == nullptr) {
			  Node* newLChild = new Node(nullptr, nullptr, _data);
			  _current->lChild = newLChild;
			  cout << _data << " was added in the left under " << _current->data << endl;
		  }
		  else {
			  addChildHelper(_current->lChild, _data);
		  }
	}
	  else {
		  if (_current->rChild == nullptr) {
			  Node* newRChild = new Node(nullptr, nullptr, _data);
			  _current->rChild = newRChild;
			  cout << _data << " was added in the right under " << _current->data << endl;

		  }
		  else {
			  addChildHelper(_current->rChild, _data);
		  }
	  }

}


Tree::~Tree()
{
}

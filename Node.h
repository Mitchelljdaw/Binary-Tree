#pragma once
struct Node
{
	Node* lChild;
	Node* rChild;
	int data;
	int bf;
	Node() {
		lChild = nullptr;
		rChild = nullptr;
		bf = 0;
		data = 0;
	};
	Node(Node* _lChild, Node* _rChild, const int &_data) {
		data = _data;
		rChild = _rChild;
		lChild = _lChild;
	};
	~Node() {
	};
};


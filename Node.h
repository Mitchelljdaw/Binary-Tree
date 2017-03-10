#pragma once
struct Node
{
	Node* lChild;
	Node* rChild;
	int data;
	Node() {
		lChild = nullptr;
		rChild = nullptr;
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


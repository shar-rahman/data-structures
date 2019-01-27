#pragma once
#include "Node.h"

class linkedList
{
public:
	Node *head;
	Node *tail;

	linkedList() {
		head = NULL;
		tail = NULL;
	}

	linkedList(int data)
	{
		head = new Node(data); tail = head;
	}

	void appendNode(Node* nuNode);
	void appendNode(int newData);
	void ListDelete(Node* removeNode);
	int getlength();
	void clear();
};




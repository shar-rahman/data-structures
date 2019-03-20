#pragma once
#include "Node.h"
#include <string>
using namespace std;

template <class dataType>
struct Greater
{
	bool operator () (dataType first, dataType second)
	{
		return first > second;
	}
};


class QueueInterface
{
public:
	virtual bool isEmpty() = 0;
	virtual void enQueue(string data, int priority) = 0;
	virtual void deQueue() = 0;
};

class PriorityQueue : QueueInterface
{
	Node* front;
	Greater<int> greater;
public:
	PriorityQueue()
	{
		srand((unsigned int)time(0));
		front = NULL;
	}
	Node* getFront() { return this->front; }
	bool isEmpty(){ return front == NULL; }
	
	void enQueue(string data, int priority)
	{
		cout << "Inserting " << data << endl;
		Node* temp = new Node(data, priority);
		if (front == NULL || greater(temp->code(), front->code()))
		{
			temp->link = front;
			front = temp;
		}
		else
		{
			Node* rover = front;
			while (rover->link != NULL && greater(rover->link->code(), temp->code()))
				rover = rover->link;
			temp->link = rover->link;
			rover->link = temp;
		}
	}
	void deQueue()
	{
		Node* rover;
		if (front == NULL)
			cout << "Queue underflow" << endl;
		else
		{
			rover = this->getFront();
			cout << "Item is: " << rover->_symbol << endl;
			front = front->link;
		}
	}
	friend ostream& operator <<(ostream& os, PriorityQueue& pque)
	{
		Node* rover = pque.getFront();
		if (pque.getFront() == NULL)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			cout << "Queue values:\t";
			while (rover != NULL)
			{
				cout << rover->_symbol << " (" << rover->code() << ") ";
				rover = rover->link;
			}
			cout << endl;
		}
		return os;
	}
};

#include "linkedList.h"

void linkedList::clear()
{
	Node* rover = head;
	Node* temp;
	while (rover != NULL)
	{
		temp = rover;
		rover = rover->next;
		ListDelete(temp);
	}

}


int linkedList::getlength()
{
	Node* rover = head;
	int i = 0;
	while (rover)
	{
		rover = rover->next;
		i++;
	}
	return i;
}


void linkedList::appendNode(int newData)
{
	Node* newNode = new Node(newData);
	appendNode(newNode);
}


void linkedList::appendNode(Node* nuNode)
{
	Node* rover;
	if (head == NULL)
	{
		head = nuNode;
	}
	else
	{
		rover = head;
		while (rover->next)
		{
			rover = rover->next;
		}
		rover->next = nuNode;
		nuNode->prev = rover;
		tail = nuNode;
	}
}

void linkedList::ListDelete(Node* removeNode)
{
	Node* temp = removeNode->next;
	Node* prevNode = removeNode->prev;
	if (temp != NULL)
	{
		temp->prev = prevNode;
	}
	if (prevNode != NULL)
	{
		prevNode->next = temp;
	}
	if (removeNode == head)
	{
		head = temp;
	}
	if (removeNode == tail)
	{
		tail = prevNode;
	}

}

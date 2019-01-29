#pragma once
#include <iostream>

class Node
{
public:
	int data;
	Node* next;
	Node* prev;
	Node() { data = 0; next = NULL; prev = NULL; }
	Node(int d) { data = d; next = NULL; prev = NULL; }
};
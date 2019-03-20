#pragma once
#include "Morse.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

class Node {
public:
	Node* link;
	string _symbol;
	int _code;
	Node() {
		_symbol = "";
		_code = 0;
		link = NULL;
	}
	Node(string str, int b)
	{
		_symbol = str;
		_code = b;
		link = NULL;
	}
	string symbol() { return _symbol; }
	int code() { return _code; }
};

class Leaf : public Node {
public:
	int _code;
	string _symbol;
	Leaf(string str, int c) : Node(str, c) {
		_symbol = str;
		for (int i = 0; i < ALPHA_SIZE; i++)
			if (MorseEncode[i].priority == c)
				_symbol = MorseEncode[i].binary;
		
	};
	int code() { return _code; }
	string symbol() { return _symbol; }
};

class Branch : public Node {
public:
	Node* _Left;
	Node* _Right;

	Branch() {
		_Left = NULL;
		_Right = NULL;
	}
	Branch(Node* L, Node* R) :Node("", L->_code + R->_code) {
		_Left = L;
		_Right = R;
	}
	Node* left() {
		return _Left;
	}
	Node* right() {
		return _Right;
	}
};
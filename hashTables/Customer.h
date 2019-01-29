#pragma once
#include "linkedList.h"
using namespace std;

class Customer
{
public:
	string lastname, firstname, id;
	Customer(); // default constructor
	Customer(string l, string f, string id); // overloaded constructor
};


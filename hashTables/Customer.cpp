#include "Customer.h"

Customer::Customer()
{
	lastname = '\0';
	firstname = '\0';
	id = '\0';
}

Customer::Customer(string l, string f, string id)
{
	lastname = l;
	firstname = f;
	id = id;
}


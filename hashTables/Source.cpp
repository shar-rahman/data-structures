#include "linkedList.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int hashKey(string id, int key);


int main() {
	int containerSize = 10;
	int length = 0;
	int hash = 0;

	string lastname, firstname, id;

	ifstream customerData;
	Customer* customers = new Customer[containerSize];
	Customer* dynamicCustomer;
	linkedList chainingHash[32];

	int chain_key = 32;

	customerData.open("Customer.csv");

	while (getline(customerData, lastname, ','))
	{
		getline(customerData, firstname, ',');
		getline(customerData, id);
		
		if (length == (containerSize - 1))
		{
			containerSize *= 2;
			dynamicCustomer = new Customer[containerSize];
			for (int i = 0; i < (containerSize / 2); i++)
				dynamicCustomer[i] = customers[i];
			delete[] customers;
			customers = new Customer[containerSize];
			for (int i = 0; i < (containerSize / 2); i++)
				customers[i] = dynamicCustomer[i];
			delete[] dynamicCustomer;
			cout << containerSize << endl;
		}	
		
		customers[length].lastname = lastname;
		customers[length].firstname = firstname;
		customers[length].id = id;

		length++;
	} 
	length--;
	
	
	for (int i = 0; i < length; i++)
	{
		hash = hashKey(id, (i%10));
		cout << hash << endl;
	}

	system("pause");
	return 0;
}

int hashKey(string id, int key)
{
	int hash = 0;
	int idLength = id.length();
	for (int i = 0; i < idLength; i++)
		hash += (id[i]);
	hash %= key;
	return hash;
}
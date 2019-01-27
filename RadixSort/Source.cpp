#include <iostream>
#include <fstream>
#include "linkedList.h"

using namespace std;


linkedList radixSort(linkedList list, int length);
int getMaxLength(linkedList list, int length);
int radixGetLength(int value);
void printList(linkedList list);

int main() {
	linkedList numbers;
	ifstream inputFile;
	int readNumbers;
	int i = 0;
	
	inputFile.open("NUMBERS.txt");
	
	if (!inputFile)
	{
		cout << "file not found" << endl;
	}
	
	while (inputFile >> readNumbers)
	{
		numbers.appendNode(readNumbers);
		i++;
	}
	
	printList(radixSort(numbers, i));

	system("pause");
	return 0;
}


void printList(linkedList list)
{
	Node* rover; 
	rover = list.head;
	std::cout << "~~~ printing list ~~~\n";
	while (rover != NULL) 
	{
		std::cout << rover->data << "\n";
		rover = rover->next;
	}
	std::cout << "\n~~~ END ~~~" << endl;
}


linkedList radixSort(linkedList list, int length)
{
	Node* rover = list.head;
	
	int *array = new int[length];
	int convert = 0;
	while (convert < length)
	{
		array[convert] = rover->data;
		rover = rover->next;
		convert++;
	}

	linkedList buckets[10];
	linkedList listOfSortedNumbers;
	Node* bucketRover;

	int maxDigits = getMaxLength(list, length);
	int bucketIndex;
	int power = 1;
	int arrayIndex = 0;
	
	for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++)
	{
		for (int i = 0; i < length; i++)
		{
			bucketIndex = abs(array[i] / power) % 10;
			buckets[bucketIndex].appendNode(array[i]);
		}
		
		arrayIndex = 0;

		for (int p = 0; p < 10; p++)
		{
			bucketRover = buckets[p].head;
			for (int j = 0; j < buckets[p].getlength(); j++, arrayIndex++) {
				array[arrayIndex] = bucketRover->data;
				bucketRover = bucketRover->next;
			}
		}
		power = power * 10;
		for (int k = 0; k < 10; k++)
		{
			buckets[k].clear();
		} 
	}
	
	int index = 0;
	while (index < length)
	{
		listOfSortedNumbers.appendNode(array[index]);
		index++;
	}

	delete array;
	return listOfSortedNumbers;
}

int getMaxLength(linkedList list, int length)
{
	int maxDigits = 0;
	int digitCount;
	Node* rover = list.head;
	for (int i = 0; i < length; i++)
	{
		digitCount = radixGetLength(rover->data);
		if (digitCount > maxDigits)
			maxDigits = digitCount;
		rover = rover->next;
	}
	return maxDigits;
}

int radixGetLength(int value)
{
	if (value == 0)
		return 1;
	int digits = 0;
	while (value != 0)
	{
		digits = digits + 1;
		value = value / 10;
	}

	return digits;
}

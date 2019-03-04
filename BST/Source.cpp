#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

int main()
{
	int data;
	BinaryTree<int> Tree;
	ifstream inFile;
	
	inFile.open("Numbers.txt");

	while (inFile >> data)
		Tree.insertNode(data);
	
	Tree.printFromRoot();
	system("pause");
	return 0;
}


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
	cout << "Creating degenerate tree: " << endl;
	while (inFile >> data)
		Tree.insertNode(data);
	
	cout << "Tree Before balancing: " << endl;
	Tree.printFromRoot(Tree.getRoot());
	cout << "==========" << endl;
	cout << "Tree After balancing: " << endl;
	Tree.balance(Tree.getRoot());
	Tree.printFromRoot(Tree.getRoot());
	system("pause");
	return 0;
}


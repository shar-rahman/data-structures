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
	
	Tree.printInOrder();
	Tree.printPostOrder();
	Tree._searchNode(Tree.getRoot(), 11022);
	Tree._searchNode(Tree.getRoot(), 1234123423);
	Tree.isBalanced();


	system("pause");
	return 0;
}


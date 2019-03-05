#pragma once
#include "TreeNode.h"
#include <queue>
#include <math.h>

using namespace std;

template <class dataType>
class BinaryTree
{
private:
	TreeNode<dataType>* root;
	int size;
public:
	BinaryTree() { root = 0; size = 0; }
	BinaryTree(dataType data) { std::cout << "Building Tree." << std::endl; this->root->setData(data); std::cout << "Success"; }
	//set
	void setRoot(dataType data) { this->root.data = data; }
	void setRoot(TreeNode<dataType>* newRoot) { this->root = newRoot; }
	void setSize(int x) { this->size = x; }
	//get
	TreeNode<dataType>* getRoot() const { return this->root; }
	dataType getRootData() const { return this->root->getData(); }
	int getSize() const { return this->size; }
	//bst functions
	void insertNode(TreeNode<dataType>* newNode);
	void insertNode(dataType newNode);
	void printInOrder(TreeNode<dataType>* node);
	void printInOrder();
	void printPostOrder(TreeNode<dataType>* node);
	void printPostOrder();
	void printFromRoot(TreeNode<dataType>* node);
	bool searchNode(TreeNode<dataType>* node, dataType key);
	// balance functions
	int getHeight(TreeNode<dataType>* node);
	bool isBalanced(TreeNode<dataType>* node);
	void rotateRight(TreeNode<dataType>* node);
	void rotateLeft(TreeNode<dataType>* node);
	void balance(TreeNode<dataType>* node);
};

template <class dataType>
void BinaryTree<dataType>::printFromRoot(TreeNode<dataType>* node)
{
	if (node == NULL)
		return;
	queue<TreeNode<dataType>*> TreeQueue;
	TreeQueue.push(node);
	while (true)
	{
		int numberOfNodes = TreeQueue.size();
		if (numberOfNodes == 0)
			break;
		while (numberOfNodes > 0)
		{
			TreeNode<dataType>* rover = TreeQueue.front();
			std::cout << rover->getData() << " ";
			TreeQueue.pop();
			if (rover->getLeft() != NULL)
				TreeQueue.push(rover->getLeft());
			if (rover->getRight() != NULL)
				TreeQueue.push(rover->getRight());
			numberOfNodes--;
		}
		std::cout << std::endl;
	}
}

template <class dataType>
void BinaryTree<dataType>::insertNode(TreeNode<dataType>* newNode)
{
	TreeNode<dataType>* rover = this->root;
	if (this->getRoot() == 0)
	{
		root = newNode;
		std::cout << "Inserting root: " << root->getData() << "\n";
	}
	else {
		bool exitCond = true;
		while (exitCond)
		{
			if(newNode->getData() > rover->getData())
			{
				if (rover->getRight() == 0)
				{
					rover->setRight(newNode);
					newNode->setParent(rover);
					exitCond = false;
					break;
				}
				else rover = rover->getRight();
			}
			else if (rover->getData() > newNode->getData())
			{
				if (rover->getLeft() == 0)
				{
					rover->setLeft(newNode);
					newNode->setParent(rover);
					exitCond = false;
					break;
				}
				else rover = rover->getLeft();
			}
			else
			{
				std::cout << "Data is the same\n\n";
				exitCond = false;
			}
		}
		newNode->setLeft(0);
		newNode->setRight(0);
	}
}

template <class dataType>
void BinaryTree<dataType>::insertNode(dataType newData)
{
	TreeNode<dataType>* newNode = new TreeNode<dataType>;
	TreeNode<dataType>* rover = this->root;

	newNode->setData(newData);

	if (this->getRoot() == 0)
	{
		root = newNode;
	}
	else {
		bool exitCond = true;
		while (exitCond)
		{
			if (newNode->getData() > rover->getData())
			{
				if (rover->getRight() == 0)
				{
					rover->setRight(newNode);
					newNode->setParent(rover);
					exitCond = false;
					break;
				}
				else rover = rover->getRight();
			}
			else if (rover->getData() > newNode->getData())
			{
				if (rover->getLeft() == 0)
				{
					rover->setLeft(newNode);
					newNode->setParent(rover);
					exitCond = false;
					break;
				}
				else rover = rover->getLeft();
			}
			else
			{
				std::cout << "Data is the same\n\n";
				exitCond = false;
			}
		}
		newNode->setLeft(0);
		newNode->setRight(0);
	}
}

template <class dataType>
void BinaryTree<dataType>::printInOrder(TreeNode<dataType>* node)
{
	if (node == NULL)
		return;

	printInOrder(node->getLeft());
	std::cout << node->getData() << std::endl;
	printInOrder(node->getRight());
}

template <class dataType>
void BinaryTree<dataType>::printInOrder()
{
	std::cout << "\nPrinting from left to right." << std::endl;
	if (this->getRoot() == NULL)
		return;

	printInOrder(this->getRoot());
}

template <class dataType>
void BinaryTree<dataType>::printPostOrder(TreeNode<dataType>* node)
{
	if (node == NULL)
		return;

	printPostOrder(node->getRight());
	std::cout << node->getData() << std::endl;
	printPostOrder(node->getLeft());
}

template <class dataType>
void BinaryTree<dataType>::printPostOrder()
{
	std::cout << "\nPrinting from right to left." << std::endl;
	if (this->getRoot() == NULL)
		return;

	printPostOrder(this->getRoot());
}

template <class dataType>
bool BinaryTree<dataType>::searchNode(TreeNode<dataType>* node, dataType key)
{
	if (node != NULL)
	{
		if (key == node->getData())
			return 1;
		else if (key < node->getData())
			return searchNode(node->getLeft(), key);
		else
			return searchNode(node->getRight(), key);
	}
	return 0;
}


template <class dataType>
int BinaryTree<dataType>::getHeight(TreeNode<dataType>* node)
{
	if (node == NULL)
		return -1;
	int leftHeight = getHeight(node->getLeft());
	int rightHeight = getHeight(node->getRight());
	if (leftHeight > rightHeight)
		return 1 + leftHeight;
	else if (leftHeight < rightHeight)
		return 1 + rightHeight;
	else
		return 1 + rightHeight;
}

template <class dataType>
bool BinaryTree<dataType>::isBalanced(TreeNode<dataType>* node)
{
	int rightHeight = getHeight(node->getRight());
	int leftHeight = getHeight(node->getLeft());
	int difference = abs(leftHeight - rightHeight);
	if (root == NULL)
		return false;
	if (difference > 1)
		return false;
	return true;
}

template <class dataType>
void BinaryTree<dataType>::rotateLeft(TreeNode<dataType>* node)
{
	if (node == this->getRoot())
	{
		this->root = node->getRight();
		node->getRight()->setParent(NULL);
		node->getRight()->setLeft(node);
		node->setParent(node->getRight());
		node->setRight(NULL);
	}
	else
	{
		node->getRight()->setParent(node->getParent());
		node->getParent()->setRight(node->getRight());
		node->getRight()->setLeft(node);
		node->setParent(node->getRight());
		node->setRight(NULL);
	}
}

template <class dataType>
void BinaryTree<dataType>::rotateRight(TreeNode<dataType>* node)
{
	if (node == this->getRoot())
	{
		this->root = node->getLeft();
		node->getLeft()->setParent(NULL);
		node->getLeft()->setRight(node);
		node->setParent(node->getLeft());
		node->setLeft(NULL);
	}
	else
	{
		node->getLeft()->setParent(node->getParent());
		node->getParent()->setLeft(node->getLeft());
		node->getLeft()->setRight(node);
		node->setParent(node->getLeft());
		node->setLeft(NULL);
	}
}

template <class dataType>
void BinaryTree<dataType>::balance(TreeNode<dataType>*node)
{
	if (node == NULL)
		return;
	while (this->isBalanced(node) == false)
	{
		int leftHeight = this->getHeight(node->getLeft());
		int rightHeight = this->getHeight(node->getRight());
		if (leftHeight > rightHeight && leftHeight - rightHeight > 1)
		{
			this->rotateRight(node);
		}
		else if (leftHeight < rightHeight && rightHeight - leftHeight > 1)
		{
			this->rotateLeft(node);
		}
		node = node->getParent();
	}
	this->balance(node->getLeft());
	this->balance(node->getRight());
}
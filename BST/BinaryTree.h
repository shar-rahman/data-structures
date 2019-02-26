#pragma once
#include "TreeNode.h"


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
	bool searchNode(TreeNode<dataType>* node, dataType key);
	void _searchNode(TreeNode<dataType>* node, dataType key);
	// balance functions
	int getHeight(TreeNode<dataType>* node);
	bool isBalanced();
	void balanceTree();
	bool setChild(TreeNode<dataType>* parent, TreeNode<dataType>* check, TreeNode<dataType>* child);
	bool replaceChild(TreeNode<dataType>* parent, TreeNode<dataType>* old, TreeNode<dataType>* nuChild);
	void rotateRight(TreeNode<dataType>* node);
	void rotateLeft(TreeNode<dataType>* node);
};

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
					std::cout << ">> Set Right >>" << std::endl;
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
					std::cout << "<< Set Left <<" << std::endl;
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
		std::cout << "Inserting root: " << root->getData() << "\n";
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
					std::cout << ">> Set Right: " << rover->getData() << " >>" << std::endl;
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
					std::cout << "<< Set Left: " << rover->getData() << " <<" << std::endl;
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
bool BinaryTree<dataType>::setChild(TreeNode<dataType>* parent, TreeNode<dataType>* check, TreeNode<dataType>* child)
{
	if (check != parent->getLeft() || check != parent->getRight())
		return false;
	if (check == parent->getLeft())
		parent->setLeft(child);
	else
		parent->setRight(child);
	if (child != NULL)
		child->setParent(parent);
	return true;
}

template <class dataType>
bool BinaryTree<dataType>::replaceChild(TreeNode<dataType>* parent, TreeNode<dataType>* old, TreeNode<dataType>* nuChild)
{
	if (parent->getLeft() == old)
		return setChild(parent, parent->getLeft(), nuChild);
	else if (parent->getRight() == old)
		return setChild(parent, parent->getRight(), nuChild);
	return false;
}

template <class dataType>
void BinaryTree<dataType>::_searchNode(TreeNode<dataType>* node, dataType key)
{
	std::cout << "Searching for: " << key << std::endl;
	if (searchNode(node, key))
		std::cout << "Found node!" << std::endl;
	else
		std::cout << "Node not found!" << std::endl;
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
bool BinaryTree<dataType>::isBalanced()
{
	std::cout << "\nChecking if tree is balanced." << std::endl;
	int rightHeight = getHeight(this->root->getRight());
	int leftHeight = getHeight(this->root->getLeft());
	int height = getHeight(this->getRoot());
	std::cout << "Tree Height: " << height << std::endl;
	std::cout << "Left Height: " << leftHeight << std::endl;
	std::cout << "Right Height: " << rightHeight << std::endl;
	if (leftHeight > rightHeight || rightHeight > leftHeight)
	{
		std::cout << "Tree not balanced.\n" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Tree is balanced.\n" << std::endl;
		return true;
	}
}

template <class dataType>
void BinaryTree<dataType>::rotateLeft(TreeNode<dataType>* node)
{
	TreeNode<dataType>* rover = node->getRight()->getLeft();
	if (node->getParent != NULL)
		replaceChild(node->getParent(), node, node->getRight());
	else
	{
		this->setRoot(node->getRight());
		this->root->setParent(NULL);
	}
	setChild(node->getRight(), node->getLeft(), node);
	setChild(node, node->getRight(), rover);
}

template <class dataType>
void BinaryTree<dataType>::rotateRight(TreeNode<dataType>* node)
{
	TreeNode<dataType>* rover = node->getLeft()->getRight();
	if (node->getParent != NULL)
		replaceChild(node->getParent(), node, node->getLeft());
	else
	{
		this->setRoot(node->getLeft());
		this->root->setParent(NULL);
	}
	setChild(node->getLeft(), node->getRight(), node);
	setChild(node, node->getLeft(), rover);
}
template <class dataType>
void BinaryTree<dataType>::balanceTree()
{
	int rightHeight = getHeight(this->root->getRight());
	int leftHeight = getHeight(this->root->getLeft());
	if (rightHeight == leftHeight)
	{
		std::cout << "Tree has been balanced." << std::endl;
		return;
	}
	else
	{
		if (rightHeight > leftHeight)
		{
			int balance = rightHeight - leftHeight;
			for (int i = 0; i < balance; i++)
				rotateLeft(this->getRoot());
		}
		else
		{
			int balance = leftHeight - rightHeight;
			for (int i = 0; i < balance; i++)
				rotateRight(this->getRoot());
		}
	}
}


#pragma once

template <class dataType> 
class TreeNode
{
private:
	dataType data;
	TreeNode<dataType>* leftPointer;
	TreeNode<dataType>* rightPointer;
	TreeNode<dataType>* parentNode;
	
public:
	//constructors
	TreeNode() { data = NULL; leftPointer = NULL; rightPointer = NULL; parentNode = NULL; }
	TreeNode(dataType newItem) { data = newItem; leftPointer = NULL; rightPointer = NULL; parentNode = NULL; }
	//setters
	void setData(dataType newItem) { this->data = newItem; }
	void setLeft(TreeNode<dataType>* left) { this->leftPointer = left; }
	void setRight(TreeNode<dataType>* right) { this->rightPointer = right; }
	void setParent(TreeNode<dataType>* parent) { this->parentNode = parent; }
	//getters
	dataType getData() { return data; }
	TreeNode<dataType>* getLeft() { return leftPointer; }
	TreeNode<dataType>* getRight() { return rightPointer; }
	TreeNode<dataType>* getParent() { return parentNode; }
};

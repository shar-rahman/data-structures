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
	TreeNode(){ data = 0; leftPointer = 0; rightPointer = 0; }
	TreeNode(dataType newItem) { setData(newItem); leftPointer = NULL; rightPointer = NULL; parentNode = NULL; }
	//setters
	void setData(dataType newItem) { data = newItem; }
	void setLeft(TreeNode<dataType>* left) { leftPointer = left; }
	void setRight(TreeNode<dataType>* right) { rightPointer = right; }
	void setParent(TreeNode<dataType>* parent) { parentNode = parent; }
	//getters
	dataType getData() { return data; }
	TreeNode<dataType>* getLeft() { return leftPointer; }
	TreeNode<dataType>* getRight() { return rightPointer; }
	TreeNode<dataType>* getParent() { return parentNode; }
};

#pragma once

#include "Person.h"

class BinarySearchNode
{
private:
	Person* data;
	BinarySearchNode* left;
	BinarySearchNode* right;
public:
	BinarySearchNode(Person* data, BinarySearchNode* left, BinarySearchNode* right);
	const int getId() const;
	BinarySearchNode* getLeft()const;
	BinarySearchNode* getRight()const;
	Person* getData()const;
	void setData(Person* data);
	void setLeft( BinarySearchNode* left);
	void setRight( BinarySearchNode* right);
	BinarySearchNode& operator=(const BinarySearchNode& b);
};


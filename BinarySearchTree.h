#pragma once

#include <vector>
#include "BinarySearchNode.h"

class BinarySearchTree
{
private:
	BinarySearchNode* root;

	BinarySearchNode* FindNodeHealper(int id, BinarySearchNode* root) const;
	BinarySearchNode* FindNode(int id) const;

	BinarySearchNode* findParentNodeHelper(const int id, BinarySearchNode* root) const;

	void InsertHealper(const int id, BinarySearchNode* newNode);
	
	void DeleteHealper(int id, BinarySearchNode* root);
	void DeleteHealperOneChildNode(BinarySearchNode* nodeToDelete, BinarySearchNode* parentNodeToDelete);
	
	BinarySearchNode* MinNodeHealper(BinarySearchNode* root) const;
	BinarySearchNode* MaxNodeHealper(BinarySearchNode* root) const;
	
	BinarySearchNode* SuccNodeHealper(int id) const;
	BinarySearchNode* PredNodeHealper(int id) const;

	void swap(BinarySearchNode* node1, BinarySearchNode* node2);
public:
	BinarySearchTree(int n);
	void MakeEmpty();
	bool IsEmpty() const;
	Person* Find(int id) const;
	BinarySearchNode* findParentNode(const int id) const;
	void Insert(int id, Person* person);
	void Delete(int id);
	Person* Min() const;
	Person* Max() const;
	Person* Succ(int id) const;
	Person* Pred(int id) const;
};


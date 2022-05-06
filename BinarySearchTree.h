#pragma once

#include <vector>
#include "BinarySearchNode.h"

class BinarySearchTree
{
private:
	BinarySearchNode* root;

	BinarySearchNode* FindNodeHealper(int id, BinarySearchNode* root) const;
	BinarySearchNode* FindNode(int id) const;

	BinarySearchNode* findParentInsertNodeHelper(const int id, BinarySearchNode* root) const;
	BinarySearchNode* findDeleteParentNode(const int id, BinarySearchNode* root) const;

	void InsertHealper(const int id, BinarySearchNode* newNode);
	
	void DeleteHealper(int id, BinarySearchNode* root);
	void DeleteHealperOneChildNode(BinarySearchNode* nodeToDelete, BinarySearchNode* parentNodeToDelete);
	
	BinarySearchNode* MinNodeHealper(BinarySearchNode* root) const;
	BinarySearchNode* MaxNodeHealper(BinarySearchNode* root) const;
	
	BinarySearchNode* SuccNodeHealper(int id) const;
	BinarySearchNode* PredNodeHealper(int id) const;

	void swap(BinarySearchNode* node1, BinarySearchNode* node2);

	void ToDLRListHealper(BinarySearchNode* root, std::vector<BinarySearchNode*>& personList) const;
public:
	BinarySearchTree();
	void MakeEmpty();
	bool IsEmpty() const;
	Person* Find(int id) const;
	BinarySearchNode* findInsertParentNode(const int id) const;
	BinarySearchNode* findDeleteParentNode(const int id) const;
	void Insert(int id, Person* person);
	void Delete(int id);
	Person* Min() const;
	Person* Max() const;
	Person* Succ(int id) const;
	Person* Pred(int id) const;
	
	const Person& getKthSmallest(const int k) const;
	BinarySearchNode* FindkSmallest(BinarySearchNode* root, int k) const;
};


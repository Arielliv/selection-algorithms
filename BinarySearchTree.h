#pragma once

#include <vector>
#include "BinarySearchNode.h"

class BinarySearchTree
{
private:
	BinarySearchNode* root;

	BinarySearchNode* FindNodeHealper(int id, BinarySearchNode* root, int& NumComp) const;
	BinarySearchNode* FindNode(int id, int& NumComp) const;

	BinarySearchNode* findParentInsertNodeHelper(const int id, BinarySearchNode* root, int& NumComp) const;
	BinarySearchNode* findDeleteParentNode(const int id, BinarySearchNode* root, int& NumComp) const;

	void InsertHealper(const int id, BinarySearchNode* newNode, int& NumComp);
	
	void DeleteHealper(int id, BinarySearchNode* root, int& NumComp);
	void DeleteHealperOneChildNode(BinarySearchNode* nodeToDelete, BinarySearchNode* parentNodeToDelete);
	
	BinarySearchNode* MinNodeHealper(BinarySearchNode* root) const;
	BinarySearchNode* MaxNodeHealper(BinarySearchNode* root) const;
	
	BinarySearchNode* SuccNodeHealper(int id, int& NumComp) const;
	BinarySearchNode* PredNodeHealper(int id, int& NumComp) const;

	void swap(BinarySearchNode* node1, BinarySearchNode* node2);

	void ToDLRListHealper(BinarySearchNode* root, std::vector<BinarySearchNode*>& personList) const;
public:
	BinarySearchTree();
	void MakeEmpty();
	bool IsEmpty() const;
	Person* Find(int id, int& NumComp) const;
	BinarySearchNode* findInsertParentNode(const int id, int& NumComp) const;
	BinarySearchNode* findDeleteParentNode(const int id, int& NumComp) const;
	void Insert(int id, Person* person, int& NumComp);
	void Delete(int id, int& NumComp);
	Person* Min() const;
	Person* Max() const;
	Person* Succ(int id, int& NumComp) const;
	Person* Pred(int id, int& NumComp) const;
	
	const Person& getKthSmallest(const int k) const;
	BinarySearchNode* FindkSmallest(BinarySearchNode* root, int k) const;
};


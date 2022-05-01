#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	this->root = NULL;
};

void BinarySearchTree::MakeEmpty() {
	this->root = NULL;
};

bool BinarySearchTree::IsEmpty() const {
	return this->root == NULL;
};

BinarySearchNode* BinarySearchTree::FindNodeHealper(int id, BinarySearchNode* root) const {
	if (this->root == NULL) {
		//error
		return NULL;
	}
	if (id == this->root->getId()) {
		return this->root;
	}
	if (id < this->root->getId()) {
		return this->FindNodeHealper(id, this->root->getLeft());
	}
	if (id > this->root->getId()) {
		return this->FindNodeHealper(id, this->root->getRight());
	}
};

BinarySearchNode* BinarySearchTree::FindNode(int id) const {
	if (this->IsEmpty()) {
		//error
		return NULL;
	}
	return this->FindNodeHealper(id, this->root);
}

Person BinarySearchTree::Find(int id) const {
	return this->FindNode(id)->getData();
}

BinarySearchNode* BinarySearchTree::findDeleteParentNode(const int id, BinarySearchNode* root) const {
	if (this->root == NULL) {
		//error
		return NULL;
	}
	if (id == this->root->getId()) {
		return this->root;
	}
	if (id < this->root->getId()) {
		return this->FindNodeHealper(id, this->root->getLeft());
	}
	if (id > this->root->getId()) {
		return this->FindNodeHealper(id, this->root->getRight());
	}
}

BinarySearchNode* BinarySearchTree::findParentInsertNodeHelper(const int id, BinarySearchNode* root) const {
	if (root->getLeft() == NULL && root->getRight() == NULL) {
		return root;
	}

	if (id < root->getId()) {
		if (root->getLeft() == NULL) {
			return root;
		}
		else {
			return this->findParentInsertNodeHelper(id, root->getLeft());
		}
	}
		
	if (id > root->getId()) {
		if (root->getRight() == NULL) {
			return root;
		}
		else {
			return this->findParentInsertNodeHelper(id, root->getRight());
		}
	}	
};

BinarySearchNode* BinarySearchTree::findInsertParentNode(const int id) const{
	return this->findParentInsertNodeHelper(id, this->root);
}

BinarySearchNode* BinarySearchTree::findDeleteParentNode(const int id) const {
	return this->findDeleteParentNode(id, this->root);
}

void BinarySearchTree::InsertHealper(const int id, BinarySearchNode* newNode){
	BinarySearchNode* parent = this->findInsertParentNode(id);

	if (id < parent->getId()) {
		parent->setLeft(newNode);
	} else {
		parent->setRight(newNode);
	}
}

void BinarySearchTree::Insert(int id, Person person) {
	BinarySearchNode* newNode = new BinarySearchNode(person, nullptr,nullptr);
	if (this->IsEmpty()) {
		this->root = newNode;
	}
	else {
		this->InsertHealper(id, newNode);
	}
};

void BinarySearchTree::DeleteHealperOneChildNode(BinarySearchNode* nodeToDelete, BinarySearchNode* parentNodeToDelete) {
	if (nodeToDelete->getLeft() != NULL) {
		if (parentNodeToDelete->getLeft() == nodeToDelete) {
			parentNodeToDelete->setLeft(nodeToDelete->getLeft());
			delete nodeToDelete;
		}
		else {
			parentNodeToDelete->setRight(nodeToDelete->getLeft());
			delete nodeToDelete;
		}
	}
	else {
		if (parentNodeToDelete->getLeft() == nodeToDelete) {
			parentNodeToDelete->setLeft(nodeToDelete->getRight());
			delete nodeToDelete;
		}
		else {
			parentNodeToDelete->setRight(nodeToDelete->getRight());
			delete nodeToDelete;
		}
	}
}

void BinarySearchTree::swap(BinarySearchNode* node1, BinarySearchNode* node2) {
	Person tmp = node1->getData();
	node1->setData(node2->getData());
	node2->setData(tmp);
}

void BinarySearchTree::DeleteHealper(int id, BinarySearchNode* root) {
	BinarySearchNode* nodeToDelete = this->FindNode(id);
	BinarySearchNode* parentNodeToDelete = this->findDeleteParentNode(id);

	if (nodeToDelete->getLeft() == NULL || nodeToDelete->getRight() == NULL) {
		this->DeleteHealperOneChildNode(nodeToDelete, parentNodeToDelete);
	}
	else {
		BinarySearchNode* maxLeft = this->MaxNodeHealper(nodeToDelete->getLeft());
		BinarySearchNode* parentMaxLeft = this->findDeleteParentNode(maxLeft->getId());

		this->swap(maxLeft, nodeToDelete);
		
		this->DeleteHealperOneChildNode(maxLeft, parentMaxLeft);
	}
}

void BinarySearchTree::Delete(int id) {
	this->DeleteHealper(id, this->root);
};

BinarySearchNode* BinarySearchTree::MinNodeHealper(BinarySearchNode* root) const {
	if (root->getLeft() == nullptr) {
		return root->getLeft();
	}
	else {
		return this->MinNodeHealper(root->getLeft());
	}
};

Person BinarySearchTree::Min() const {
	if (this->IsEmpty()) {
		//error
	}
	return this->MinNodeHealper(this->root)->getData();
};

BinarySearchNode* BinarySearchTree::MaxNodeHealper(BinarySearchNode* root) const {
	if (root->getRight() == nullptr) {
		return root->getRight();
	}
	else {
		return this->MaxNodeHealper(root->getRight());
	}
};

Person BinarySearchTree::Max() const {
	if (this->IsEmpty()) {
		//error
	}
	return this->MaxNodeHealper(this->root)->getData();
};

BinarySearchNode* BinarySearchTree::SuccNodeHealper(int id) const {
	BinarySearchNode* node = this->FindNode(id);
	return this->MinNodeHealper(node->getRight());
};


Person BinarySearchTree::Succ(int id) const {
	return this->SuccNodeHealper(id)->getData();
};

BinarySearchNode* BinarySearchTree::PredNodeHealper(int id) const {
	BinarySearchNode* node = this->FindNode(id);
	return this->MaxNodeHealper(node->getLeft());
};

Person BinarySearchTree::Pred(int id) const {
	return this->PredNodeHealper(id)->getData();
};

std::vector<Person> BinarySearchTree::ToDLRList() const {
	std::vector<Person> personList;
	this->ToDLRListHealper(this->root, personList);
	return personList;
}

void BinarySearchTree::ToDLRListHealper(BinarySearchNode* root, std::vector<Person>& personList) const {
	if (root == NULL) {
		return;
	}
	
	personList.push_back(root->getData());

	this->ToDLRListHealper(root->getLeft(), personList);

	this->ToDLRListHealper(root->getRight(), personList);
}
BinarySearchNode* BinarySearchTree::FindkSmallest(BinarySearchNode* root, int k) const {
	if (root == NULL) {
		return NULL;
	}
		
	BinarySearchNode* left = FindkSmallest(root->getLeft(), k);

	if (left != NULL) {
		return left;
	}
	else {
		k--;
	}
	
	if (k == 0) {
		return root;
	}	

	return FindkSmallest(root->getRight(), k);
}

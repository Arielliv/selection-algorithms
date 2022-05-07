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

BinarySearchNode* BinarySearchTree::FindNodeHealper(int id, BinarySearchNode* root, int& NumComp) const {
	if (this->root == NULL) {
		//error
		return NULL;
	}
	if (id == this->root->getId()) {
		NumComp++;
		return this->root;
	}
	if (id < this->root->getId()) {
		NumComp++;
		return this->FindNodeHealper(id, this->root->getLeft(), NumComp);
	}
	if (id > this->root->getId()) {
		NumComp++;
		return this->FindNodeHealper(id, this->root->getRight(), NumComp);
	}
};

BinarySearchNode* BinarySearchTree::FindNode(int id, int& NumComp) const {
	if (this->IsEmpty()) {
		//error
		return NULL;
	}
	return this->FindNodeHealper(id, this->root, NumComp);
}

Person* BinarySearchTree::Find(int id, int& NumComp) const {
	return this->FindNode(id,NumComp)->getData();
}

BinarySearchNode* BinarySearchTree::findDeleteParentNode(const int id, BinarySearchNode* root, int& NumComp) const {
	if (this->root == NULL) {
		//error
		return NULL;
	}
	if (id == this->root->getId()) {
		NumComp++;
		return this->root;
	}
	if (id < this->root->getId()) {
		NumComp++;
		return this->FindNodeHealper(id, this->root->getLeft(), NumComp);
	}
	if (id > this->root->getId()) {
		NumComp++;
		return this->FindNodeHealper(id, this->root->getRight(), NumComp);
	}
}

BinarySearchNode* BinarySearchTree::findParentInsertNodeHelper(const int id, BinarySearchNode* root, int& NumComp) const {
	if (root->getLeft() == NULL && root->getRight() == NULL) {
		return root;
	}

	if (id < root->getId()) {
		NumComp++;
		if (root->getLeft() == NULL) {
			return root;
		}
		else {
			return this->findParentInsertNodeHelper(id, root->getLeft(), NumComp);
		}
	}
		
	if (id > root->getId()) {
		NumComp++;
		if (root->getRight() == NULL) {
			return root;
		}
		else {
			return this->findParentInsertNodeHelper(id, root->getRight(),NumComp);
		}
	}	
};

BinarySearchNode* BinarySearchTree::findInsertParentNode(const int id, int& NumComp) const{
	return this->findParentInsertNodeHelper(id, this->root, NumComp);
}

BinarySearchNode* BinarySearchTree::findDeleteParentNode(const int id, int& NumComp) const {
	return this->findDeleteParentNode(id, this->root, NumComp);
}

void BinarySearchTree::InsertHealper(const int id, BinarySearchNode* newNode, int& NumComp){
	BinarySearchNode* parent = this->findInsertParentNode(id,NumComp);

	if (id < parent->getId()) {
		NumComp++;
		parent->setLeft(newNode);
	} else {
		NumComp++;
		parent->setRight(newNode);
	}
}

void BinarySearchTree::Insert(int id, Person* person, int& NumComp) {
	BinarySearchNode* newNode = new BinarySearchNode(person, nullptr,nullptr);
	if (this->IsEmpty()) {
		this->root = newNode;
	}
	else {
		this->InsertHealper(id, newNode, NumComp);
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
	BinarySearchNode* tmp = node1;
	node1 = node2;
	node2 = tmp;
}

void BinarySearchTree::DeleteHealper(int id, BinarySearchNode* root, int& NumComp) {
	BinarySearchNode* nodeToDelete = this->FindNode(id, NumComp);
	BinarySearchNode* parentNodeToDelete = this->findDeleteParentNode(id, NumComp);

	if (nodeToDelete->getLeft() == NULL || nodeToDelete->getRight() == NULL) {
		this->DeleteHealperOneChildNode(nodeToDelete, parentNodeToDelete);
	}
	else {
		BinarySearchNode* maxLeft = this->MaxNodeHealper(nodeToDelete->getLeft());
		BinarySearchNode* parentMaxLeft = this->findDeleteParentNode(maxLeft->getId(), NumComp);

		this->swap(maxLeft, nodeToDelete);
		
		this->DeleteHealperOneChildNode(maxLeft, parentMaxLeft);
	}
}

void BinarySearchTree::Delete(int id, int& NumComp) {
	this->DeleteHealper(id, this->root, NumComp);
};

BinarySearchNode* BinarySearchTree::MinNodeHealper(BinarySearchNode* root) const {
	if (root->getLeft() == nullptr) {
		return root->getLeft();
	}
	else {
		return this->MinNodeHealper(root->getLeft());
	}
};

Person* BinarySearchTree::Min() const {
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

Person* BinarySearchTree::Max() const {
	if (this->IsEmpty()) {
		//error
	}
	return this->MaxNodeHealper(this->root)->getData();
};

BinarySearchNode* BinarySearchTree::SuccNodeHealper(int id, int& NumComp) const {
	BinarySearchNode* node = this->FindNode(id, NumComp);
	return this->MinNodeHealper(node->getRight());
};


Person* BinarySearchTree::Succ(int id, int& NumComp) const {
	return this->SuccNodeHealper(id,NumComp)->getData();
};

BinarySearchNode* BinarySearchTree::PredNodeHealper(int id, int& NumComp) const {
	BinarySearchNode* node = this->FindNode(id,NumComp);
	return this->MaxNodeHealper(node->getLeft());
};

Person* BinarySearchTree::Pred(int id, int& NumComp) const {
	return this->PredNodeHealper(id, NumComp)->getData();
};

const Person& BinarySearchTree::getKthSmallest(const int k) const {
	std::vector<BinarySearchNode *> personList;
	this->ToDLRListHealper(this->root, personList);
	return *(personList[k-1]->getData());
}

void BinarySearchTree::ToDLRListHealper(BinarySearchNode* root, std::vector<BinarySearchNode *>& personList) const {
	if (root == NULL) {
		return;
	}
	
	this->ToDLRListHealper(root->getLeft(), personList);
	
	personList.push_back(root);

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

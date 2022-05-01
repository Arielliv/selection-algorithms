#include "BinarySearchNode.h"

BinarySearchNode::BinarySearchNode(Person data, BinarySearchNode* left, BinarySearchNode* right): data(data), left(left), right(right) {};

int BinarySearchNode::getId() const {
	return this->data.getId();
};

BinarySearchNode* BinarySearchNode::getLeft()const {
	return this->left;
};

BinarySearchNode* BinarySearchNode::getRight()const {
	return this->right;
};

void BinarySearchNode::setLeft( BinarySearchNode* left) {
	this->left = left;
};

void BinarySearchNode::setRight( BinarySearchNode* right) {
	this->right = right;
};

Person BinarySearchNode::getData()const {
	return this->data;
}

void BinarySearchNode::setData(Person data) {
	this->data = data;
}
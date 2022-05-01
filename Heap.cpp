#include "Heap.h"

Heap::Heap(int n) {
	this->minTree.reserve(n);
	this->heapSize = 0;
};

Heap::Heap(Person* personList, int n) {
	this->minTree.reserve(n);
	for (int i = 0; i < n; i++) {
		this->minTree.push_back(Person(personList[i]));
	}
	for (int i = (n / 2) - 1; i >= 0; i--) {
		this->heapifyUpBottom(i);
	}
	this->heapSize = n;
}

void Heap::MakeEmpty() {
	this->minTree.clear();
	this->heapSize = 0;
};

bool Heap::IsEmpty() const{
	return this->heapSize == 0;
};

Person Heap::Min() const {
	return this->minTree[0];
};

void Heap::Insert(int id, Person person) {
	int index = this->heapSize - 1;
	this->minTree.push_back(person);
	this->heapifyBottomUp(index);
	this->heapSize++;
}

Person Heap::DeleteMin() {
	Person returnValue = this->minTree[0];
	int index = this->heapSize - 1;
	this->swap(0, index);
	this->heapSize--;
	this->heapifyUpBottom(0);
	return returnValue;
}

void Heap::heapifyUpBottom(int index) {
		int smalest = index;
		int leftIndex = 2 * index + 1; // left
		int rightIndex = 2 * index + 2; // right

		
		if (leftIndex < this->heapSize && (this->minTree[leftIndex]).getId() < (this->minTree[smalest]).getId()) {
			smalest = leftIndex;
		}

		if (rightIndex < this->heapSize && (this->minTree[rightIndex]).getId() < (this->minTree[smalest]).getId()) {
			smalest = rightIndex;
		}
			
		if (smalest != index) {
			this->swap(index, smalest);

			this->heapifyUpBottom(smalest);
		}
	
}

void Heap::heapifyBottomUp(int index){
	int parent = (index - 1) / 2; // parent

	if (parent > 0) {
		if ((this->minTree[index]).getId() < (this->minTree[parent]).getId()) {
			this->swap(index, parent);

			this->heapifyBottomUp(parent);
		}
	}
}

void Heap::swap(int index1, int index2) {
	Person tmp = this->minTree[index1];
	this->minTree[index1] = this->minTree[index2];
	this->minTree[index2] = tmp;
};


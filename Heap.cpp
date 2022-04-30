#include "Heap.h"

Heap::Heap(int n) {
	this->maxTree.reserve(n);
};

void Heap::MakeEmpty() {
	this->maxTree.clear();
};

bool Heap::IsEmpty() const{
	return this->maxTree.size() == 0;
};

Person* Heap::Max() const {
	return this->maxTree[0];
};

void Heap::Insert(int id, Person* person) {
	int index = this->maxTree.size() - 1;
	this->maxTree.push_back(person);
	this->heapifyBottomUp(index);
}

Person Heap::DeleteMax() {
	Person returnValue = Person(*(this->maxTree[0]));
	int index = this->maxTree.size() - 1;
	this->swap(0, index);
	delete this->maxTree[index];
	this->heapifyUpBottom(0);
	return returnValue;
}

void Heap::heapifyUpBottom(int index) {
		int largest = index;
		int leftIndex = 2 * index + 1; // left
		int rightIndex = 2 * index + 2; // right

		
		if ((*this->maxTree[leftIndex]).getId() > (*this->maxTree[largest]).getId()) {
			largest = leftIndex;
		}

		if ((*this->maxTree[rightIndex]).getId() > (*this->maxTree[largest]).getId()) {
			largest = rightIndex;
		}
			
		if (largest != index) {
			this->swap(index, largest);

			this->heapifyUpBottom(largest);
		}
	
}

void Heap::heapifyBottomUp(int index){
	int parent = (index - 1) / 2; // parent

	if (parent > 0) {
		if ((*this->maxTree[index]).getId() > (*this->maxTree[parent]).getId()) {
			this->swap(index, parent);

			this->heapifyBottomUp(parent);
		}
	}
}

void Heap::swap(int index1, int index2) {
	Person* tmp = this->maxTree[index1];
	this->maxTree[index2] = this->maxTree[index1];
	this->maxTree[index1] = tmp;
};


#pragma once
#include <vector>
#include "Person.h"

class Heap
{
private:
	std::vector<Person *> maxTree;

	void heapifyBottomUp(int index);
	void heapifyUpBottom(int index);
	void swap(int index1, int index2);
public:
	Heap() {};
	Heap(int n);
	void MakeEmpty();
	bool IsEmpty() const;
	Person* Max() const;
	void Insert(int id, Person* person);
	Person DeleteMax();
	
};


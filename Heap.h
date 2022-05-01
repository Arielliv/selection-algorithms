#pragma once
#include <vector>
#include "Person.h"

class Heap
{
private:
	std::vector<Person> minTree;
	int heapSize = 0;

	void heapifyBottomUp(int index);
	void heapifyUpBottom(int index);
	void swap(int index1, int index2);
public:
	Heap() {};
	Heap(int n);
	Heap(Person* personList, int n);
	void MakeEmpty();
	bool IsEmpty() const;
	Person Min() const;
	void Insert(int id, Person person);
	Person DeleteMin();
	
};


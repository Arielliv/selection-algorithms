#pragma once

#include "Person.h"

class RandomSelection{
private:
	int Partition(Person* personList[], int left, int right);
	int RandomPivotPartition(Person* personList[], int start, int end);
	Person* SelectionHealper(Person* personList[], int left, int right, int id);
	void swap(Person* personList[], int index1, int index2);
	int getRandomNum(int min, int amount) const;
public:
	RandomSelection() {};
	const Person& Selection(Person personList[], int n, int k);
};


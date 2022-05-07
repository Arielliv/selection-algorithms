#pragma once

#include "Person.h"

class RandomSelection{
private:
	int Partition(Person* personList[], int left, int right, int& NumComp);
	int RandomPivotPartition(Person* personList[], int start, int end, int& NumComp);
	Person* SelectionHealper(Person* personList[], int left, int right, int id, int& NumComp);
	void swap(Person* personList[], int index1, int index2);
public:
	RandomSelection() {};
	const Person& Selection(Person personList[], int n, int k, int& NumComp);
};


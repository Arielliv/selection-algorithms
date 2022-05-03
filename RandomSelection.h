#pragma once

#include "Person.h"
class RandomSelection{
private:
	int Partition(Person personList[], int left, int right);
	int RandomPivotPartition(Person personList[], int start, int end);
	Person SelectionHealper(Person personList[], int left, int right, int id);
	void swap(Person& person1, Person& person2);
	int getRandomNum(int min, int amount) const;
public:
	RandomSelection() {};
	void initRandomize() const;
	Person Selection(Person personList[], int n, int k);
};


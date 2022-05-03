#include "RandomSelection.h"

void RandomSelection::initRandomize() const{
    srand(time(NULL));
}

int RandomSelection::getRandomNum(int min, int amount) const{
    return (min + rand() % (amount));
}

void RandomSelection::swap(Person& person1, Person& person2) {
	Person tmp = person1;
	person1 = person2;
	person2 = tmp;
}

// Partitioning the array on the basis of values at high as pivot value.
int RandomSelection::Partition(Person personList[], int start, int end) {
	int pivotIndex, index, i;
	index = start;
	pivotIndex = end;

	// Getting index of pivot.
	for (i = start; i < end; i++)
	{
		if (personList[i].getId() < personList[pivotIndex].getId()){
			this->swap(personList[i], personList[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	this->swap(personList[pivotIndex], personList[index]);

	return index;
}

// Random selection of pivot.
int RandomSelection::RandomPivotPartition(Person personList[], int start, int end){
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = start + n % (end - start + 1);

	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	this->swap(personList[end], personList[pvt]);

	return Partition(personList, start, end);
}

Person RandomSelection::SelectionHealper(Person personList[], int left, int right, int k)  {
	int pivotIndex;
	int leftPart;
       
	pivotIndex = this->RandomPivotPartition(personList, left, right);
	leftPart = pivotIndex - left + 1;
	if (k == leftPart) {
		return personList[pivotIndex];
	}
	if (k < leftPart) {
		return this->SelectionHealper(personList, left, pivotIndex - 1, k);
	}
	else {
		return this->SelectionHealper(personList, pivotIndex +1, right, k- leftPart);
	}
}

Person RandomSelection::Selection(Person personList[], int n,int k)  {
	return this->SelectionHealper(personList, 0, n-1, k);
}
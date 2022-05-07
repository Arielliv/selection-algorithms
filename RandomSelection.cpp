#include "RandomSelection.h"

void RandomSelection::swap(Person* personList[], int index1, int index2) {
	Person* tmp = personList[index1];
	personList[index1] = personList[index2];
	personList[index2] = tmp;
}

// Partitioning the array on the basis of values at high as pivot value.
int RandomSelection::Partition(Person* personList[], int start, int end, int& NumComp) {
	int pivotIndex, index, i;
	index = start;
	pivotIndex = end;

	// Getting index of pivot.
	for (i = start; i < end; i++)
	{
		if (personList[i]->getId() < personList[pivotIndex]->getId()){
			this->swap(personList,i, index);
			index++;
		}
		NumComp++;
	}
	// Swapping value at high and at the index obtained.
	this->swap(personList,pivotIndex, index);

	return index;
}

// Random selection of pivot.
int RandomSelection::RandomPivotPartition(Person* personList[], int start, int end, int& NumComp){
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = start + n % (end - start + 1);

	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	this->swap(personList,end,pvt);

	return Partition(personList, start, end, NumComp);
}

Person* RandomSelection::SelectionHealper(Person* personList[], int left, int right, int k, int& NumComp)  {
	int pivotIndex;
	int leftPart;
       
	pivotIndex = this->RandomPivotPartition(personList, left, right, NumComp);
	leftPart = pivotIndex - left + 1;
	if (k == leftPart) {
		NumComp++;
		return personList[pivotIndex];
	}
	if (k < leftPart) {
		NumComp++;
		return this->SelectionHealper(personList, left, pivotIndex - 1, k,NumComp);
	}
	else {
		NumComp++;
		return this->SelectionHealper(personList, pivotIndex +1, right, k- leftPart, NumComp);
	}
}

const Person& RandomSelection::Selection(Person personList[], int n,int k, int& NumComp)  {
	Person** personListP = new Person*[n];
	for (int i = 0; i < n; i++)
	{
		personListP[i] = &(personList[i]);
	}
	return *(this->SelectionHealper(personListP, 0, n-1, k, NumComp));
}
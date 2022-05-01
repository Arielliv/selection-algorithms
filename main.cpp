#include "UserInput.h"
#include "Person.h"
#include "Heap.h"

const Person& selectHeap(Person[], int n, int k, int& NumComp);
const Person& BST(Person[], int n, int k, int& NumComp);
const Person& RandSelection(Person personList[], int n, int k, int& NumComp);

int main() {
	int n, k, NumComp =0;
	UserInput userInput = UserInput();
	userInput.getPersonListSize(n);
	

	Person* personList = new Person[n];
	userInput.getPersonList(n, personList);
	userInput.getPersonKListSize(k);
	selectHeap(personList, n, k, NumComp);

}

const Person& selectHeap(Person personList[], int n, int k, int& NumComp) {
	Person* personKList = new Person[k];
	Heap personHeap = Heap(personList, n);
	for (int i = 0; i < k; i++) {
		personKList[i] = personHeap.DeleteMin();
	}
	return personKList[k-1];
}
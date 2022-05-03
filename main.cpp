#include "UserInput.h"
#include "Person.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include "RandomSelection.h"

const Person& SelectHeap(Person personList[], int n, int k, int& NumComp);
const Person& BST(Person personList[], int n, int k, int& NumComp);
const Person& RandSelection(Person personList[], int n, int k, int& NumComp);

int main() {
	int n, k, NumComp =0;
	UserInput userInput = UserInput();
	userInput.getPersonListSize(n);
	

	Person* personList = new Person[n];
	userInput.getPersonList(n, personList);
	userInput.getPersonKListSize(k);
	
	// 3 different algoritems to get the k smallest number
	RandSelection(personList, n, k, NumComp);
	BST(personList, n, k, NumComp);
	SelectHeap(personList, n, k, NumComp);

}

const Person& SelectHeap(Person personList[], int n, int k, int& NumComp) {
	Person personK;
	Heap personHeap = Heap(personList, n);
	for (int i = 0; i < k; i++) {
		personK = personHeap.DeleteMin();
	}
	return personK;
}

const Person& BST(Person personList[], int n, int k, int& NumComp) {
	Person personK;
	BinarySearchTree BSTree = BinarySearchTree();
	for (int i = 0; i < n; i++)
	{
		BSTree.Insert(personList[i].getId(),personList[i]);
	}
	std::vector<Person> personKList = BSTree.ToDLRList();
	return personKList[k - 1];
}

const Person& RandSelection(Person personList[], int n, int k, int& NumComp) {
	Person personK;
	RandomSelection randomSelection = RandomSelection();
	randomSelection.initRandomize();
	personK = randomSelection.Selection(personList, n, k);
	return personK;
}
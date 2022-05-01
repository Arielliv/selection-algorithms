#include "UserInput.h"
#include "Person.h"
#include "Heap.h"
#include "BinarySearchTree.h"

const Person& selectHeap(Person personList[], int n, int k, int& NumComp);
const Person& BST(Person personList[], int n, int k, int& NumComp);
const Person& RandSelection(Person personList[], int n, int k, int& NumComp);

int main() {
	int n, k, NumComp =0;
	UserInput userInput = UserInput();
	userInput.getPersonListSize(n);
	

	Person* personList = new Person[n];
	userInput.getPersonList(n, personList);
	userInput.getPersonKListSize(k);
	BST(personList, n, k, NumComp);
	selectHeap(personList, n, k, NumComp);

}

const Person& selectHeap(Person personList[], int n, int k, int& NumComp) {
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

//const Person& RandSelection(Person personList[], int n, int k, int& NumComp) {
//
//}
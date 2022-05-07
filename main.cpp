#include "UserInput.h"
#include "Person.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include "RandomSelection.h"
#include "Utils.h"
#include <algorithm>
#include <iterator>
#include <stdlib.h>


const Person& SelectHeap(Person personList[], int n, int k, int& NumComp);
const Person& BST(Person personList[], int n, int k, int& NumComp);
const Person& RandSelection(Person personList[], int n, int k, int& NumComp);

int main() {
	int n, k, NumComp =0,r;
	Utils utils = Utils();
	UserInput userInput = UserInput();
	userInput.getRandomInput(r);
	utils.initRandomize(r);
	userInput.getPersonListSize(n);
	

	Person* personList = new Person[n];
	Person* BpersonList = new Person[n];
	Person* HpersonList = new Person[n];

	userInput.getPersonList(n, personList, BpersonList, HpersonList);
	userInput.getPersonKListSize(k);
	if (k > n) {
		std::cout << "invalid input" << std::endl;
		exit(1);
	}
	
	// 3 different algoritems to get the k smallest number
	const Person& RandSelectionPersonK = RandSelection(personList, n, k, NumComp);
	std::cout << "RandSelection: " << RandSelectionPersonK << ' ' << NumComp << " comparisons" << std::endl;

	const Person& SelectHeapPersonK = SelectHeap(HpersonList, n, k, NumComp);
	std::cout << "selectHeap: " << SelectHeapPersonK << ' ' << NumComp << " comparisons" << std::endl;

	const Person& BSTPersonK = BST(BpersonList, n, k, NumComp);
	std::cout << "BST: " << BSTPersonK << ' ' << NumComp << " comparisons" << std::endl;
}

const Person& SelectHeap(Person personList[], int n, int k, int& NumComp) {
	Heap personHeap = Heap(personList, n, NumComp);
	for (int i = 0; i < k-1; i++) {
		 personHeap.DeleteMin(NumComp);
	}
	return personHeap.DeleteMin(NumComp);
}

const Person& BST(Person personList[], int n, int k, int& NumComp) {
	Person personK;
	BinarySearchTree BSTree = BinarySearchTree();
	for (int i = 0; i < n; i++)
	{
		BSTree.Insert(personList[i].getId(), &(personList[i]), NumComp);
	}
	return BSTree.getKthSmallest(k);
}

const Person& RandSelection(Person personList[], int n, int k, int& NumComp) {
	RandomSelection randomSelection = RandomSelection();
	return randomSelection.Selection(personList, n, k, NumComp);
}
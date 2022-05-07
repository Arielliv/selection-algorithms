#include "UserInput.h"

void UserInput::getRandomInput(int& n) {
	//for debuging
	std::cout << "Please enter random num\n" << ">>";
	std::cin >> n;
}

void UserInput::getPersonListSize(int &n ) {
	
		//for debuging
		std::cout << "Please enter user list size\n" << ">>";
		std::cin >> n;
}

void UserInput::getPersonKListSize(int& k) {
	//for debuging
	std::cout << "Please enter user K list size\n" << ">>";
	std::cin >> k;
}

bool UserInput::getPersonList(int n, Person RpersonList[], Person BpersonList[], Person HpersonList[]) {
	int id;
	std::string firstName, lastName;
	std::vector<int> existingIds;
	int personCounter = 0;

	while (personCounter < n) {
		//for debuging
		existingIds.reserve(n);
		std::cout << "Please enter user for list\n" << ">>";
		std::cin >> id >> firstName >> lastName;
		checkIsIdExistInArray(existingIds, id);
		RpersonList[personCounter] = Person(id,firstName,lastName);
		BpersonList[personCounter] = Person(id, firstName, lastName);
		HpersonList[personCounter] = Person(id, firstName, lastName);
		existingIds.push_back(id);
		personCounter++;
	}
	return true;
}

void UserInput::checkIsIdExistInArray(std::vector<int>& existingIds, int id) const {
	for (int i = 0; i < existingIds.size(); i++) {
		if (id == existingIds[i]) {
			exit(1);
		}
	}
}

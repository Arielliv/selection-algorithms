#include "UserInput.h"

void UserInput::getPersonListSize(int& n) {

	//for debuging
	std::cout << "Please enter user list size\n" << ">>";
	std::cin >> n;
}

void UserInput::getPersonKListSize(int& k) {
	//for debuging
	std::cout << "Please enter user K list size\n" << ">>";
	std::cin >> k;
}

bool UserInput::getPersonList(int n, Person personList[]) {
	int id;
	std::string firstName, lastName;
	int personCounter = 0;

	while (personCounter < n) {
		//for debuging
		std::cout << "Please enter user for list\n" << ">>";
		std::cin >> id >> firstName >> lastName;
		personList[personCounter] = Person(id, firstName, lastName);
		personCounter++;
	}
	return true;
}


#pragma once
#include <iostream>
#include <string>       // std::string
#include <sstream>
#include "Person.h"

class UserInput
{
public:
	UserInput() {};
	void getPersonListSize(int& n);
	void getPersonKListSize(int& k);
	bool getPersonList(int n, Person personList[]);
};


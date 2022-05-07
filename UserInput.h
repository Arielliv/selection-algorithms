#pragma once
#include <iostream>
#include <string>       // std::string
#include <sstream>
#include "Person.h"
#include <stdlib.h>
#include <vector>

class UserInput	
{
private:
	void checkIsIdExistInArray(std::vector<int>& existingIds, int id) const;
public:
	UserInput() {};
	void getRandomInput(int& n);
	void getPersonListSize(int& n);
	void getPersonKListSize(int& k);
	bool getPersonList(int n, Person RpersonList[], Person BpersonList[], Person HpersonList[]);
};


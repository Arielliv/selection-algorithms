#pragma once
#include <iostream>
#include <string>

class Person
{
private:
	int id;
	std::string firstName;
	std::string lastName;
public:
	Person(int id, std::string firstName, std::string lastName);
	Person(const Person& p);
	int getId() const;
	void print() const;
};


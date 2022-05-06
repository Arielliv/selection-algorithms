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
	Person() {};
	Person(int id, std::string firstName, std::string lastName);
	const int getId() const;
	void print() const;
	Person& operator=(const Person& b);
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};


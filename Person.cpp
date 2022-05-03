#include "Person.h"

Person::Person(int id, std::string firstName, std::string lastName):id(id), firstName(firstName), lastName(lastName) {};
Person::Person(const Person& p):id(p.id), firstName(p.firstName), lastName(p.lastName){};

int Person::getId() const {
	return this->id;
};

void Person::print() const {
	std::cout << this->id << " " << this->firstName << " " << this->lastName << std::endl;
};

Person& Person::operator=(const Person& b) {
	this->id = b.id;
	this->firstName = b.firstName;
	this->lastName = b.lastName;
	return *this;
}
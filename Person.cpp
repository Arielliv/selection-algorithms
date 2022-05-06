#include "Person.h"

Person::Person(int id, std::string firstName, std::string lastName):id(id), firstName(firstName), lastName(lastName) {};

const int Person::getId() const {
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

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.id << ' ' << p.firstName << ' ' << p.lastName;
	return os;
}
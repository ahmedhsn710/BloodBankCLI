#include "Person.h"

Person::Person()
	:
	name("lol"), ID("123"), bloodtype(BloodType::Group::B, BloodType::RHfactor::plus)
{
}

std::string Person::GetName() const
{
	return name;
}

std::string Person::GetID() const
{
	return ID;
}

void Person::setname(std::string n)
{
	name = n;
}

void Person::setID(std::string i)
{
	ID = i;
}

void Person::Inputbloodtype()
{
	std::cin >> bloodtype;
}

BloodType Person::GetBloodType() const
{
	return bloodtype;
}

std::ostream& operator << (std::ostream& os, const Person &p)
{
	os << "Name: " << p.name;
	os << ", ID: " << p.ID;
	os << ", Blood Type " << p.bloodtype;

	return os;
}

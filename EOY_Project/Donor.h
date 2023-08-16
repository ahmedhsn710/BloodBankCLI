#ifndef DONOR_h
#define DONOR_h

#include "Person.h"
#include "MedicalReport.h"
#include <iostream>

class Donor : public Person
{
public:
	Donor();
	void setaddress(std::string a);
	std::string getaddress();
	void setcontactno(std::string c);
	std::string getcontactno();
	void setmedrep(MedicalReport mr);
	BloodType GetBloodType() const;
	friend std::ostream& operator<<(std::ostream& os, const Donor& d);
	void Inputbloodtype();
private:
	std::string Address, contactNo;
	MedicalReport medRep;
	bool bloodAvailable;
};

#endif // !DONOR


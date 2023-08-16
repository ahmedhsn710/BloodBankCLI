#include "Person.h"
#include "patientfilehandler.h"
 
class Patient : public Person
{
	std::string address;
	std::string contactNo;
    std::string disease;
	patientfilehandler fhandler;

public:
	Patient();
    Patient(Person Person, std::string disease);
	void Inputbloodtype();
	void setaddress(std::string a);
	void setcontactno(std::string c);
    void setdisease(std::string d);
	void AddToFile(std::string donorID);
};
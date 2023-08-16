#ifndef BLOODBANK
#define BLOODBANK

#include <string>
#include <vector>
#include "Donor.h"
#include "bloodbankfilehandler.h"
#include "donorfilehandler.h"

class BloodBank
{
public:
	BloodBank();
	BloodBank(std::string name);
	void FillDonorsFromFile();
	void AddDonor(Donor d);
	void DisplayAllDonorData() const;
private:
	bloodbankfilehandler bfilehandler;
	std::string name, address, contactNo;
	donorfilehandler dfilehandler;
	std::vector<Donor> donors;
};

#endif // !BLOODBANK
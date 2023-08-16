#include "BloodBank.h"
#include <iostream>

BloodBank::BloodBank()
	:
	bfilehandler("Bloodbank_data.csv"),
	dfilehandler("Donor_data.csv")
{
}

BloodBank::BloodBank(std::string name)
	:
	bfilehandler("Bloodbank_data.csv"),
	name(name),
	address(bfilehandler.getAddress(name)),
	contactNo(bfilehandler.getContactNo(name)),
	dfilehandler("Donor_data.csv")
{
	FillDonorsFromFile();
}

// mainly used to load the data from csv into program to make the search more efficient. dont need to interact with the cvs again and again.
void BloodBank::FillDonorsFromFile()
{
	for (string ID : dfilehandler.GetIDsofDonorsFromBank(name))
	{
		donors.emplace_back(dfilehandler.returndonor(ID));
	}
}

void BloodBank::AddDonor(Donor d)
{
	donors.emplace_back(d);
}

void BloodBank::DisplayAllDonorData() const
{
	for (const Donor& d : donors)
	{
		std::cout << d << "\n";
	}
}

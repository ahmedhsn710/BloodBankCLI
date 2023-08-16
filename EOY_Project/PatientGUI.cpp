#include "GUI.h"

using namespace std;

void PatientGUI::Go()
{
	string buffer;

	cout << "Please enter your name: ";
	GeneralGUI::GetInput(buffer);
	p.setname(buffer);

	cout << "Please enter your id: ";
	GeneralGUI::GetInput(buffer);
	p.setID(buffer);

	cout << "Please enter your blood type: ";
	p.Inputbloodtype();
	
	cout << "Please enter your address: ";
	GeneralGUI::GetInput(buffer);
	p.setaddress(buffer);
	
	cout << "Please enter your contact No.: ";
	GeneralGUI::GetInput(buffer);
	p.setcontactno(buffer);

	cout << "Please enter any of your diseases: ";
	GeneralGUI::GetInput(buffer);
	p.setdisease(buffer);

	cout << "\nHere is data for all donors\n";
	if (BloodType::DonationPossible(BloodType::Oplus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_O+");
	}
	if (BloodType::DonationPossible(BloodType::Ominus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_O-");
	}

	if (BloodType::DonationPossible(BloodType::Aplus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_A+");
	}
	if (BloodType::DonationPossible(BloodType::Aminus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_A-");
	}

	if (BloodType::DonationPossible(BloodType::Bplus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_B+");
	}
	if (BloodType::DonationPossible(BloodType::Bminus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_B-");
	}

	if (BloodType::DonationPossible(BloodType::ABplus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_AB+");
	}
	if (BloodType::DonationPossible(BloodType::ABminus(), p.GetBloodType()))
	{
		dfile.read_record_bysearch("_AB-");
	}
	
	while (true)
	{
		cout << "\nPlease enter the ID of the Donor you'd like to recieve data from: ";
		GeneralGUI::GetInput(buffer);

		try
		{
			string donorName = dfile.GetNameFromID(buffer);
			if (donorName == "ID not found") throw donorName;
			cout << "You have chosen " << donorName << "\nYou will be contacted further through your contact number for further updates.";
			p.AddToFile(buffer);
			dfile.delete_record(stoi(buffer));
			cout << "Your data has been added to our database\n";
			break;
		}
		catch (string error)
		{
			cout << error;
		}
	}
}
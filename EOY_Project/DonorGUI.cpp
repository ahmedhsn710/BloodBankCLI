#include "GUI.h"

using namespace std;

void DonorGUI::Go()
{
	string buffer;
	MedicalReport temp;
	int numBuffer;

	cout << "Please enter your name: ";
	GeneralGUI::GetInput(buffer);
	d.setname(buffer);

	cout << "Please enter your id: ";
	GeneralGUI::GetInput(buffer);
	d.setID(buffer);

	cout << "Please enter your bloodtype: ";
	d.Inputbloodtype();

	cout << "Please enter your address: ";
	GeneralGUI::GetInput(buffer);
	d.setaddress(buffer);

	cout << "Please enter your contact number: ";
	GeneralGUI::GetInput(buffer);
	d.setcontactno(buffer);

	cout << "Please enter some details about your medical report here\n";
	cout << "Please enter your age: ";
	GeneralGUI::GetInput(numBuffer);
	temp.SetAge(numBuffer);

	cout << "Please enter your body weight: ";
	GeneralGUI::GetInput(numBuffer);
	temp.SetWeight(numBuffer);

	cout << "Please enter your haemoglobin level: ";
	GeneralGUI::GetInput(numBuffer);
	temp.SetHaemLev(numBuffer);

	d.setmedrep(temp);

	if (temp.Eligible()) {
		cout << "Your medical report has been received. You are eligible to donate blood.\n";

		cout << "Here is the list of Blood Banks you can donate to:\n";
		
		bfile.displayAll();

		cout << "\nEnter the name of the bank you'd like to donate to: ";
		GeneralGUI::GetInput(buffer);

		cout << "You have chosen" << buffer << "\nYour data will be stored with us. Thank you for donating blood!";
		
		dfile.createdonor(d.GetName(), d.getaddress(), d.getcontactno(), "_" + d.GetBloodType().GetString() , buffer, d.GetID(), "YES");
	}
	else
	{
			cout << "Sorry but you cannot donate blood as you did not meet the eligibility criteria.";
	}
	
}
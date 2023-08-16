#include "GUI.h"
#include <iostream>

int main()
{
	std::cout << "BLOOD DONATION SYSTEM\n\n";
	std::cout << "Are you a patient(p) or a donor(d)?\n";
	char choices[] = { 'p', 'd' };
	char input;
	GeneralGUI::GetInput(choices, sizeof(choices), input);

	PatientGUI patientGUI;
	DonorGUI donorGUI;

	if (input == 'p') patientGUI.Go();
	else donorGUI.Go();
	
	return 0;
}
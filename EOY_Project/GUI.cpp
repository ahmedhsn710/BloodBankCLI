#include "GUI.h"
#include <iostream>

void GeneralGUI::GetInput(char * validChoices, int nChoices, char & storeTo)
{
	bool Invalid = true;

	while (Invalid)
	{
		std::cin >> storeTo;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < nChoices; i++)
		{
			if (storeTo == validChoices[i]) Invalid = false;
		}

		if (Invalid)
		{
			std::cout << "Please Enter a valid input\n";
		}
	}
}

void GeneralGUI::GetInput(std::string& storeTo)
{
	storeTo = "";
	getline(cin, storeTo);
}

void GeneralGUI::GetInput(int & storeTo)
{
	std::cin >> storeTo;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


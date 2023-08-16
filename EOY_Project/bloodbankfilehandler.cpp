#include "bloodbankfilehandler.h"

bloodbankfilehandler::bloodbankfilehandler(string fname)
{
	setfilename(fname);
}

void bloodbankfilehandler::createBank(string Bname, string Baddress, string Bcontact)
{
	std::ofstream OutFile(getfilename());

	OutFile << Bname << ","
		<< Baddress << ","
		<< Bcontact << '\n';

	OutFile.close();
}

string bloodbankfilehandler::getAddress(string Bname)
{
	std::ifstream fin(getfilename());
	string line;

	while (getline(fin, line))
	{
		string CurName = "";
		for (int i = 0; true; i++)
		{
			if (line[i] == ',') break;
			CurName += line[i];
		}

		if (CurName == Bname)
		{
			string address = "";
			for (int i = (int)Bname.size() + 1; true; i++)
			{
				if (line[i] == ',') break;
				address += line[i];
			}
			fin.close();
			return address;
		}
	}
	fin.close();
	return "ID not found";
}

string bloodbankfilehandler::getContactNo(string Bname)
{
	std::ifstream fin(getfilename());
	string line;

	while (getline(fin, line))
	{
		string CurName = "";
		for (int i = 0; true; i++)
		{
			if (line[i] == ',') break;
			CurName += line[i];
		}

		if (CurName == Bname)
		{
			string contactno = "";
			for (int i = (int)Bname.size() + 1 + (int)getAddress(Bname).size() + 1; true; i++)
			{
				if (line[i] == '\n') break;
				contactno += line[i];
			}
			fin.close();
			return contactno;
		}
	}
	fin.close();
	return "ID not found";
}

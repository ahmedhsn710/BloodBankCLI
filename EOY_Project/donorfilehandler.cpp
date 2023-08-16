#include "donorfilehandler.h"
#include <string>
#include <cstring>

using namespace std;

 
donorfilehandler ::donorfilehandler(string fname){
    donorfilehandler ::setfilename(fname);
}
void donorfilehandler::createdonor(string Dname,string Daddress,string Dcontact,string Dbloodtype,string Dbloodbank,string Did,string Available)
{
// file pointer
fstream foutcreate;

// opens an existing csv file or creates a new file.
foutcreate.open(getfilename(), ios::out | ios::app);

    // Insert the data to file
    foutcreate << Did << ", "
            << Dname << ", "
            << Daddress << ", "
            << Dcontact << ", "
            << Dbloodtype << ", "
            << Dbloodbank << ", "
            << Available
            << "\n";

    cout <<" Data of Donor "<<Dname<<" Inserted Successfully."<<endl;

}

string donorfilehandler::GetNameFromID(string ID)
{
	ifstream fin(getfilename());
	string line;

	while (getline(fin, line))
	{
		string CurID = "";
		for (int i = 0; true; i++)
		{
			if (line[i] == ',') break;
			CurID += line[i];
		}

		if (CurID == ID)
		{
			string name = "";
			for (int i = (int)ID.size() + 1; true; i++)
			{
				if (line[i] == ',') break;
				name += line[i];
			}
			fin.close();
			return name;
		}
	}
	fin.close();
	return "ID not found";
}

vector<string> donorfilehandler::GetIDsofDonorsFromBank(string Bname)
{
	vector<string> R;
	char separator = ',';
	string row, item;

	ifstream in(getfilename());

	while (getline(in, row))
	{
		string CurBname;
		stringstream ss(row);
		for (int i = 0; i < 5; i++) getline(ss, CurBname, separator);


		if (CurBname == Bname) {
			stringstream ss(row);
			getline(ss, item, separator);
			R.push_back(item);
		}
	}
	in.close();
	return R;
}

Donor donorfilehandler::returndonor(string ID)
{
	vector<string> R;
	char separator = ',';
	string row, item;

	ifstream in(getfilename());

	while (getline(in, row))
	{
		string Cid;
		for (int i = 0; true; i++) {
			if ((row[i]) == separator)break;
			Cid += row[i];
		}


		if (Cid == ID) {
			stringstream ss(row);
			while (getline(ss, item, separator)) R.push_back(item);
		}
	}
	Donor donor;
	donor.setID(R[0]);
	donor.setname(R[1]);
	donor.setaddress(R[2]);
	donor.setcontactno(R[3]);

	in.close();
	return donor;
}

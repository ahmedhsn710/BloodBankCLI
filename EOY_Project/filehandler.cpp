#include "filehandler.h"
#include <string>

using namespace std;

void filehandler::setfilename(string name)
{
    filename = name;
}

string filehandler::getfilename()
{
    return filename;
}

void filehandler::read_record_bysearch(string tofind)
{
    ifstream myfile;
    myfile.open(filename);

    while (myfile.good())
    {
        string line;
        getline(myfile, line, ',');

		for( std::string line; getline( myfile, line ); )
		{
			if (line.find(tofind) != std::string::npos) {
				std::cout << line << endl;
			}
		}
    }
}

void filehandler::delete_record(int ID)
{

	// Open FIle pointers
	fstream fin, fout;

	// Open the existing file
	fin.open(filename, ios::in);

	// Create a new file to store the non-deleted data
	fout.open("temp.csv", ios::out);

	int id1, count = 0, i;
	string line, word;
	vector<string> row;


	// Check if this record exists
	// If exists, leave it and
	// add all other data to the new file
	while (!fin.eof()) {

		row.clear();
		getline(fin, line);
		if (line.size() == 0) break;

		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);
		}

		int row_size = (int)row.size();
		id1 = std::stoi(row[0]);

		// writing all records,
		// except the record to be deleted,
		// into the new file 'reportcardnew.csv'
		// using fout pointer
		if (id1 != ID) {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {
					fout << row[i] << ", ";
				}
				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			count = 1;
		}
		if (fin.eof())
			break;
	}
    fin.close();
    fout.close();
    remove(filename.c_str());
    rename("temp.csv", filename.c_str());
	if (count == 1){
		cout << "Record deleted\n";       
    }
	else{
		cout << "Record not found\n";
    }

}

void filehandler::displayAll() const
{
	ifstream fin;
	fin.open(filename);
	string line;
	while (getline(fin, line, ','))
	{
		if (line == "") break;
		cout << line << ",";
	}
	fin.close();
}




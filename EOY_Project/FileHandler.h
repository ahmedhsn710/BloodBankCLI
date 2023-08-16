#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>

class filehandler{
    std::string filename;
	
public:
void setfilename(std::string name);
std::string getfilename();
void read_record_bysearch(std::string tofind);
void delete_record(int ID);
void displayAll() const;
};
#endif



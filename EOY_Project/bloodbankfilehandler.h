#ifndef BLOODBANKFILEHANDLER_h
#define BLOODBANKFILEHANDLER_h

#include "FileHandler.h"
#include <string>

using std::string;

class bloodbankfilehandler : public filehandler
{
public:
    bloodbankfilehandler(string fname);
    void createBank(string Bname, string Baddress, string Bcontact);
    string getAddress(string Bname);
    string getContactNo(string Bname);
};

#endif

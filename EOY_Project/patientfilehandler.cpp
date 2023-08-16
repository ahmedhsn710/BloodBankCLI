#include "filehandler.h"
#include "patientfilehandler.h"
#include <string>
#include <cstring>
    
patientfilehandler::patientfilehandler(string fname){
setfilename(fname);
}
void patientfilehandler ::createpatient(string Pid, string Pname, string Paddress, string Pcontact, string Pbloodtype, string Pdisease, string Did)
{
// file pointer
fstream foutcreate;

// opens an existing csv file or creates a new file.
foutcreate.open(getfilename(), ios::out | ios::app);

    // Insert the data to file
    foutcreate << Pid << ", " 
			<< Pname << ", "
            << Paddress << ", "
            << Pcontact << ", "
            << Pbloodtype << ", "
            << Pdisease << ", "
            << Did << ", "
            << "\n";

    cout <<" Data of Patient "<<Pname<<" Inserted Successfully."<<endl;

}
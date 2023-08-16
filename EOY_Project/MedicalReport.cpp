#include "MedicalReport.h"

using namespace std;

bool MedicalReport::weight_check(){
   return weight > 45;
}

bool MedicalReport::age_check(){
    return age >= 18;
}

bool MedicalReport::haemoglobin_level_check(){
    return haemoglobin_level > 12.5;
}

bool MedicalReport::Eligible()
{return weight_check() && age_check() && haemoglobin_level_check(); 
}

void MedicalReport::SetWeight(int w)
{
	weight = w;
}

void MedicalReport::SetAge(int a)
{
	age = a;
}

void MedicalReport::SetHaemLev(int hl)
{
	haemoglobin_level = hl;
}

void MedicalReport::SetDesease(bool d)
{
	Disease = d;
}

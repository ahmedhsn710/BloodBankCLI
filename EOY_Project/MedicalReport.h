#ifndef MEDICALREP
#define MEDICALREP

class MedicalReport{
    int weight,age,haemoglobin_level;
    bool Disease;
private:
    bool weight_check();
    bool age_check();
    bool haemoglobin_level_check();
public:
    bool Eligible();   
	void SetWeight(int w);
	void SetAge(int a);
	void SetHaemLev(int hl);
	void SetDesease(bool d);
};

#endif
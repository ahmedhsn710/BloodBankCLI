#ifndef BLOODTYPE
#define BLOODTYPE

#include <iostream>
#include <string>

class BloodType
{
public:
	enum class Group
	{
		O, A, B, AB
	};
	enum class RHfactor
	{
		plus, minus
	};
public:
	BloodType() = default;
	BloodType(Group group, RHfactor rhfactor);
	std::string GetString();
	static bool DonationPossible(BloodType donor, BloodType recipient);
	friend std::ostream& operator<<(std::ostream& os, const BloodType& b);
	friend std::istream& operator>>(std::istream& is, BloodType& b);
public:
	static BloodType Oplus();
	static BloodType Ominus();
	static BloodType Aplus();
	static BloodType Aminus();
	static BloodType Bplus();
	static BloodType Bminus();
	static BloodType ABplus();
	static BloodType ABminus();
private:
	Group group;
	RHfactor rhfactor;
};

#endif // !BLOODTYPE

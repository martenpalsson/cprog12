#ifndef JULIAN_H
#define JULIAN_H
#include "gregorian.h"
using namespace std;
namespace lab2{
struct Julian:Gregorian {
	Julian();
	Julian(int year, int month, int day);
	Julian(const Date & d);
	Julian(const Date * d);
	//Date & operator=(const Date & d);
	int mod_julian_day() const;
	void JDN_to_date();
	int leap_year(int y) const;
	Julian operator++(int);
	Julian operator--(int);
	using Date::operator++;
	using Date::operator--;
};
};
#endif

#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "date.h"
#include <vector>
#include <string>
using namespace std;

namespace lab2{

class Julian;

struct Gregorian: public Date {
	static vector<string> day_names;
	static vector<string> month_names;
	static vector<int> month_length;
	
	Gregorian();
	Gregorian(int year, int month, int day);
	Gregorian(const Julian & jul);
	Gregorian(const Julian * jul);
	Gregorian(const Date & date);
	Gregorian(const Date * date);
	int days_per_week() const;
	int days_this_month() const;
	int months_per_year() const;
	string week_day_name() const;
	string month_name() const;
	Date & add_year(int n = 1);
	Date & add_month(int n = 1);
	virtual int mod_julian_day() const; //17/11 1858 onsdag
	Gregorian operator++(int);
	Gregorian operator--(int);
	using Date::operator++;
	using Date::operator--;
	
	protected:
	virtual void JDN_to_date();
	virtual int leap_year(int y) const;
	void add_single_month();
	int m_l(int n) const;
	void remove_month(int n);
	void remove_single_month();
};
};
#endif


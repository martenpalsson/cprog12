#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;
namespace lab2{
struct Date {
protected:
	int JDN;
	int d;
	int m;
	int y;

public:
	virtual int days_per_week() const =0;
	virtual int days_this_month() const =0;
	virtual int months_per_year() const =0;
	virtual string week_day_name() const =0;
	virtual string month_name() const =0;
	Date & operator++(){JDN++;JDN_to_date();return *this;};
	Date & operator--(){JDN--;JDN_to_date();return *this;};
	Date & operator+=(int n){JDN+=n;JDN_to_date();return *this;};
	Date & operator-=(int n){JDN-=n;JDN_to_date();return *this;};
	Date & operator=(const Date & date){
		JDN = date.mod_julian_day();
		JDN_to_date();
		return *this;
	}
	virtual Date & add_year(int n = 1)=0;
	virtual Date & add_month(int n = 1)=0;
	friend ostream & operator<<(ostream & os, const Date & b);
	int year() const{ return y;};
	int month() const {return m;};
	int day() const{return d;};
	int week_day() const{
		int day = (JDN+2)%7+1;
		if(day <= 0)
			day += 7;
		return day;
	} //dag 0 = onsdag
	virtual int mod_julian_day() const = 0;
	bool operator==(const Date & date) const {
		return (mod_julian_day() == date.mod_julian_day());
	};
	bool operator!=(const Date & date) const{
		return (mod_julian_day() != date.mod_julian_day());
	};
	bool operator>=(const Date & date) const{
		return (mod_julian_day() >= date.mod_julian_day());
	};
	bool operator<=(const Date & date) const{
		return (mod_julian_day() <= date.mod_julian_day());
	};
	bool operator<(const Date & date) const{
		return (mod_julian_day() < date.mod_julian_day());
	};
	bool operator>(const Date & date) const{
		return (mod_julian_day() > date.mod_julian_day());
	};
	int operator-(const Date & date) const{ //diff mellan 2 datum
		return (mod_julian_day() - date.mod_julian_day());
	};
	protected:
	virtual void JDN_to_date() = 0;
};
};
#endif

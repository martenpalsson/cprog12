#include "kattistime.h"
#include <iostream>
#include <string>
#include "julian.h"
#include <time.h>
#include <stdexcept>
using namespace std;
namespace lab2{
Julian::Julian(){
	time_t  t;
	t = k_time(NULL);
	t = t/60/60/24;
	y = 1970;
	m = 1;
	d = 1;
	JDN = mod_julian_day() - 13 + t;
	JDN_to_date();
}

Julian::Julian(int year, int month, int day){
	if(month < 1 || month > 12){
		throw out_of_range("Month must be within the range [1:12]");
	}
	y = year;
	m = month;
	if(day < 1 || day > m_l(month)){
		throw out_of_range("Day must be in the range [1:month length]");
	}
	d = day;
	JDN = mod_julian_day();
}
Julian::Julian(const Date & date){
	JDN = date.mod_julian_day();
	JDN_to_date();
}

Julian::Julian(const Date * date){
	JDN = date->mod_julian_day();
	JDN_to_date();
}

int Julian::mod_julian_day() const{
	int A,Y,M,jdn = 0;
	A = (14-m)/12;
	Y = y+4800-A;
	M = m + 12*A - 3;
	jdn = d + (153*M +2)/5 + 365*Y + Y/4 - 32083;
	jdn = jdn - 2400001;
	return jdn;
}

void Julian::JDN_to_date(){
	//int a = JDN + 2400001 + 32044;
	int b = 0;
	int c = JDN + 2400001 + 32082;
	int D = (4*c + 3)/1461;
	int e = c - (1461*D)/4;
	int M = (5*e + 2)/153;
	y = b*100 + D - 4800 + M/10;
	m = M + 3 - 12*(M/10); 
	d = e - (153*M+2)/5 + 1;
}


int Julian::leap_year(int year) const{
	if(year%4 == 0)
		return 1;
	else
		return 0;
}


Julian Julian::operator++(int){
	Julian j = *this;
	JDN++;
	JDN_to_date();
	return j;
}

Julian Julian::operator--(int){
	Julian j = *this;
	JDN--;
	JDN_to_date();
	return j;
}
};

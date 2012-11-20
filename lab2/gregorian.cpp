#include "kattistime.h"
#include <iostream>
#include <string>
#include "gregorian.h"
#include "julian.h"
#include <time.h>
#include <stdexcept>
using namespace std;


namespace lab2{
vector<string> Gregorian::day_names = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
vector<string> Gregorian::month_names = {"january","february","march","april","may","june","july","august","september","october","november","december"};
vector<int> Gregorian::month_length = {31,28,31,30,31,30,31,31,30,31,30,31};


Gregorian::Gregorian(){
	time_t t = k_time(NULL);
	t = t/60/60/24;
	y = 1970;
	m = 1;
	d = 1;
	JDN = mod_julian_day()+ t;
	JDN_to_date();

}

Gregorian::Gregorian(int year, int month, int day){
	if(month < 1 || month >12){
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
Gregorian::Gregorian(const Julian & jul){
	JDN = jul.mod_julian_day();
	JDN_to_date();
}

Gregorian::Gregorian(const Julian * jul){
	JDN = jul->mod_julian_day();
	JDN_to_date();
}

Gregorian::Gregorian(const Date & date){
	JDN = date.mod_julian_day();
	JDN_to_date();
}

Gregorian::Gregorian(const Date * date){
	JDN = date->mod_julian_day();
	JDN_to_date();
}

int Gregorian::mod_julian_day() const{
	int A,Y,M,jdn = 0;
	A = (14-m)/12;
	Y = y+4800-A;
	M = m + 12*A - 3;
	jdn = d + (153*M +2)/5 + 365*Y + Y/4 - Y/100 + Y/400 - 32045;
	jdn = jdn - 2400001;
	return jdn;
}

void Gregorian::JDN_to_date(){
	int J = JDN + 2400001;
	int j = J + 32044;
	int g = j/146097;
	int dg = j%146097;
	int c = ((dg/36524 + 1)*3)/4;
	int dc = dg - c*36524;
	int b = dc/1461;
	int db = dc%1461;
	int a = (db/365 + 1)*3/4;
	int da = db - a*365;
	int Y = g*400 + c*100 + b*4 + a;
	int M = (da*5 + 308)/153 - 2;
	int D = da - (M+4)*153/5 + 122;
	y = Y - 4800 + (M+2)/12;
	m = (M+2)%12 + 1;
	d = D + 1; 
}


int Gregorian::days_per_week() const{
	return 7;
}

int Gregorian::days_this_month() const{
		return m_l(m); 
}

int Gregorian::months_per_year() const{
	return 12;
}

string Gregorian::week_day_name() const{
	int index = (JDN+2)%7;
	if(index < 0){
		index = index + 7;
	}
	return day_names[index];
}

string Gregorian::month_name() const{
	if(m < 1 || m > 12)
		throw out_of_range("Month is too large in month_name (or too small)");
	return month_names[m-1];
}

Date & Gregorian::add_year(int n){
	JDN_to_date();//tester
	if(d == 29 && m == 2 && leap_year(y)){ //leap day
		if(leap_year(y+n)){
			y += n;
			JDN = mod_julian_day();
		} else {
			y += n;
			d = 28;
			JDN = mod_julian_day();
		}
	} else {
		y += n;
		JDN = mod_julian_day();
	}
	return *this;
}

Date & Gregorian::add_month(int n){
	JDN_to_date();//tester
	if( n < 0){
		remove_month(n);
		return *this;
	}
	for(;n>0;n--){
		if(d <= m_l(m+1)){
			add_single_month();
		}
		else if(m+1 == 2 && d == 29 && leap_year(y)){
			add_single_month();
		}
		else {
			JDN += 30;
			JDN_to_date();
		}
	}
	return *this;
}

void Gregorian::remove_month(int n){
	JDN_to_date();//tester
	for(;n<0;n++){
		if(d > m_l(m-1)){
			JDN -= 30;
			JDN_to_date();
		}else{
			remove_single_month();
		}
	}
}

void Gregorian::remove_single_month(){
	int month_length = m_l(m-1);
	JDN -= month_length;
	JDN_to_date();
}

int Gregorian::m_l(int n) const{
	if(n == 2 && leap_year(y)){
		return 29;
	}
	if(n > 12)
		return month_length[0];
	else if(n<1)
		return month_length[11];
	else
		return month_length[n-1];
}

void Gregorian::add_single_month(){
	JDN_to_date(); //tester
	int month_length = m_l(m);
	JDN += month_length;
	JDN_to_date();
}

ostream & operator<<(ostream & os, const Date & d){
	os << d.year() << "-";
	if(d.month() < 10)
		os << 0;
	os << d.month() << "-";
	if(d.day() < 10)
		os << 0;
	os << d.day();
	return os;
}

int Gregorian::leap_year(int year) const{
	if(year%4 == 0){
		if(year%100 == 0){
			if(year%400 == 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 1;
		}
	}
	else{
		return 0;
	}
}

Gregorian Gregorian::operator++(int){
	Gregorian g = *this;
	JDN++;
	JDN_to_date();
	return g;
}

Gregorian Gregorian::operator--(int){
	Gregorian g = *this;
	JDN--;
	JDN_to_date();
	return g;
}
/*
int main(){
	
	Gregorian a;
	Gregorian b(2012,2,28);
	return 0;
}*/

};

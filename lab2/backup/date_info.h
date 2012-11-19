#include <iostream>
using namespace std;
struct D{
	int month;
	int day;

	D():month(0),day(0){};
			
	D(int m, int d){
		month = m;
		day = d;
	}
	
	D(const D & orig){
		month = orig.month;
		day = orig.day;
	}

	D & operator=(const D & orig){
		month = orig.month;
		day = orig.day;
	}

	void print(){
		cout << day << "/" << month << endl;
	}
};

int diff;
int year_sd_gregorian[701];
int year_sd_julian[701];
int leap_year_gregorian[701];
int leap_year_julian[701];
D daynum_to_date[365];
D daynum_to_date_ly[366];
void init_date_info();

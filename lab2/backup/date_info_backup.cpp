#include "date_info.h"
#include <iostream>
using namespace std;

void init_leap_year(){
	int res;
	for(int i = 1858; i < 2559; i++){
		if(i%4){
			leap_year_gregorian[i-1858] = 0; //1 = skåttår
			leap_year_julian[i-1858] = 0;
		}
		else{
			leap_year_gregorian[i-1858] = 1; //1 = skåttår
			leap_year_julian[i-1858] = 1;
		}
	}
	leap_year_gregorian[1900-1858] = 0;
	leap_year_gregorian[2100-1858] = 0;
	leap_year_gregorian[2200-1858] = 0;
	leap_year_gregorian[2300-1858] = 0;
	leap_year_gregorian[2500-1858] = 0;
}

void init_year_sd(){
	int gregorian_day = 0;
	int julian_day = 0;
	diff = 0;

	for(int i = 1858; i < 2559;i++){
		year_sd_gregorian[i-1858] = gregorian_day;
		year_sd_julian[i-1858] = julian_day;
		
		if(i==1970)
			diff = gregorian_day;

		gregorian_day += 365;
		julian_day += 365;
		if(leap_year_gregorian[i-1858])
			gregorian_day += 1;
		if(leap_year_julian[i-1858])
			julian_day += 1;
		
	}	

}

void init_year_dates(){
	int month_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int day_num = 0;
	for(int month = 0; month < 12; month++){
		for(int day = 0; day < month_length[month];day++){
			daynum_to_date[day_num].month= month+1;
			daynum_to_date[day_num].day= day+1;
			day_num++;
		}
	}
	
	month_length[1]= 29;
	day_num = 0;
	for(int month = 0; month < 12; month++){
		for(int day = 0; day < month_length[month];day++){
			daynum_to_date_ly[day_num].month= month+1;
			daynum_to_date_ly[day_num].day= day+1;
			day_num++;
		}
	}
}


void init_date_info(){
	init_leap_year();
	init_year_sd();
	init_year_dates();
}

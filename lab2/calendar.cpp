#include "calendar.h"
#include <iostream>
#include <string>
#include "gregorian.h"
#include "kattistime.h"
#include "julian.h"
#include "date.h"
using namespace std;
namespace lab2{
	template <typename T>
	ostream & operator<<(ostream & os, const Calendar<T> & cal){
		for(auto it = cal.events.begin(); it != cal.events.end(); it++){
			os << it->first << " : " << it->second << endl;
		}
		return os;
	}
};

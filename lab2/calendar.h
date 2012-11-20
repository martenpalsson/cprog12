#ifndef CALENDAR_H
#define CALENDAR_H
#include "date.h"
#include "julian.h"
#include "gregorian.h"
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
namespace lab2{
#define TODAY "TODAY"
template <typename D>
struct Calendar{
	D today;
	//Här spaDar vi events
	multimap<D, string> events;
	//default-konstruktor
	template <typename T>
	friend ostream & operator<<(ostream & os, const Calendar<T> & cal);
	
	Calendar<D>(){
		today = D();
	}

	template <typename T>
	Calendar<D>(const Calendar<T> & cal){
		events.clear();
		today = cal.today;
		for(auto it = cal.events.begin(); it != cal.events.end(); it++){
			events.insert({it->first, it->second});
		}
	}

	//Tilldelning
	template<typename T>
	Calendar<D> & operator=(const Calendar<T> & cal){
		events.clear();
		today = cal.today;
		for(auto it = cal.events.begin(); it != cal.events.end(); it++){
			events.insert({it->first, it->second});
		}
		return *this;
	}	

	bool set_date(int year, int month, int day){
		try{
			today = D(year,month,day);
		} catch(out_of_range){
			return false;
		}
		return true;
	}

	//4 event versioner
	bool add_event(string event){
		for(auto it = events.find(today); it != events.end(); ++it){
			if(it->first != today){
				break;
			}
			if(it->second == event)
				return false;
		}
		events.insert({today, event});
		return true;
	}

	bool add_event(string event, int day){
		return add_event(event, day, today.month(), today.year());
	}

	bool add_event(string event, int day, int month){
		return add_event(event, day, month, today.year());
	}

	bool add_event(string event, int day, int month, int year){
		try{
			D d(year,month,day);

			for(auto it = events.find(d); it != events.end(); ++it){
				if(it->first != d){
					break;
				}
				if(it->second == event)
					return false;
			}
			events.insert({d, event});
		} catch(out_of_range){
			return false;
		} 
		return true;
	}

	bool remove_event(string event, int day, int month, int year){
		try{
			D d(year,month,day);

			for(auto it = events.find(d); it != events.end(); it++){
				if(it->first != d){
					break;
				}
				if(it->second == event){
					events.erase(it);
					return true;
				}
			}
		} catch(out_of_range){
			return false;
		}
		return false;
	}
	
	bool remove_event(string event, int day, int month){
		return remove_event(event,day,month,today.year());
	}
	
	bool remove_event(string event, int day){
		return remove_event(event, day, today.month(), today.year());
	}
	bool remove_event(string event){
		for(auto it = events.find(today); it != events.end(); it++){
			if(it->first != today)
				break;
			if(it->second == event){
				events.erase(it);
				return true;
			}
		}
		return false;
	}
};

template <typename D>
ostream & operator<<(ostream & os, const Calendar<D> & cal){
	D d = cal.today;
	auto it = cal.events.find(d);
	++it;
	for(; it != cal.events.end(); ++it){
		os << it->first << " : " << it->second << endl;
	}

	return os;
}
}
#endif

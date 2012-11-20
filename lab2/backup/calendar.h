#ifndef CALENDAR_H
#define CALENDAR_H
#include "date.h"
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
		cout << "DEFAULT" << endl;
		today = D();
	}

	template <typename T>
	Calendar<D>(const Calendar<T> & cal){
		cout << "Copy construtor" << endl;
		events.clear();
		today = cal.today;
		for(auto it = cal.events.begin(); it != cal.events.end(); it++){
			D tmp = it->first;
			events.insert(it, pair<D,string>(tmp, it->second));
		}
	}

	//Tilldelning
	template<typename T>
	Calendar<D> & operator=(const Calendar<T> & cal){
		cout << "Tilldelning" << endl;
		events.clear();
		today = cal.today;
		for(auto it = cal.events.begin(); it != cal.events.end(); it++){
			D tmp = it->first;
			events.insert(it, pair<Date,string>(tmp, it->second));
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
		for(auto it = events.find(today); it != events.end(); it++){
			if(it->first != today){
				return true;
			}
			if(it->second == event)
				return false;
		}
		events.insert(pair<D, string>(today,event));
		return true;
	}

	bool add_event(string event, int day){
		return add_event(event);
	}

	bool add_event(string event, int day, int month){
		return add_event(event);
	}

	bool add_event(string event, int day, int month, int year){
		try{
			D d(year,month,day);

			for(auto it = events.find(d); it != events.end(); it++){
				if(it->first != today){
					return true;
				}
				if(it->second == event)
					return false;
			}

			events.insert(pair<D, string>(d,event));
		} catch(out_of_range){
			return false;
		}
		return true;
	}

	bool remove_event(string event, int day, int month, int year){
		try{
			D d(year,month,day);

			for(auto it = events.find(d); it != events.end(); it++){
				if(it->first != today){
					return false;
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
		return remove_event(event);
	}
	
	bool remove_event(string event, int day){
		return remove_event(event);
	}
	bool remove_event(string event){
		for(auto it = events.find(today); it != events.end(); it++){
			if(it->first != today)
				return false;
			else if(it->second == event){
				events.erase(it);
				return true;
			}
		}
		return false;
	}



};
}
#endif

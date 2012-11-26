#include "environ.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;
namespace game{
	
	//returns the description of the current environment
	string Environment::description(){
		return descr;
	}
	
	//Get a reference to the neigbour in the chosen direction
	Environment & Environment::neighbour(string direction){
		auto it = exits.find(direction);
		return it->second; //KAN VARA EXITS.END()!!
	}
		
	//Get a description of all the possible directions from the current 
	//environment
	void Environment::directions(){
		cout << "The possible directions are: " << endl;
		for(auto iter = exits.begin(); iter != exits.end(); iter++){
			cout << iter->first << ": " << iter->second.description() << endl;
		}
	}

	void Environment::leave(Character character){
		for(auto it = characters.begin(); it != characters.end(); it++){
			if(character == *it){
				characters.erase(it);
				return;
			}
		}
		cout << "ERROR LEAVE" << endl;
		return;
	}

	void Environment::enter(Characters character){
		characters.push_back(character);
		return;
	}

	void Environment::pick_up(Object obj){
		for(auto iter = objects.begin(); iter != objects.end(); iter++){
			if(obj.name() == *iter.name()){
				objects.erase(iter);
				return;
			}
		}
		cout << "ERROR PICK_UP" << endl;
		return;
	}
	
	void Environment::drop(Object obj){
		objects.push_back(obj);
	}
};

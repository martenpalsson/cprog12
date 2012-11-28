#include "environment.h"
#include "object.h"
#include "character.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;
namespace game{
/*	
	Environment::Environment(string description, int id2){
		descr = description;
		id = id2;
	}
*/
	Environment & Environment::operator=(const Environment & e){
		exits = e.exits;
		descr = e.descr;
		objects = e.objects;
		characters = e.characters;
		id = e.id;
		return *this;
	}

	bool Environment::operator==(const Environment & env){
		if(env.get_id() == get_id()){
			return true;
		}
		return false;
	}

	int Environment::get_id() const{
		return id;
	}
	
	//returns the description of the current environment
	string Environment::description() const{
		return descr;
	}
	
	bool Environment::set_neighbour(string direction, Environment * e){
		return exits.insert({direction, e}).second;
	}
	
	//Get a reference to the neigbour in the chosen direction
	bool Environment::neighbour(Environment * env, string direction){
		
		auto it = exits.find(direction);
		env = it->second; 
		return it == exits.end();
	}
		
	//Get a description of all the possible directions from the current 
	//environment
	void Environment::directions() const{
		cout << "The possible directions are: " << endl;
		for(auto iter = exits.begin(); iter != exits.end(); iter++){
			cout << iter->first << ": " << iter->second->description() << endl;
		}
	}
	
	void Environment::leave(Character & character){
		for(auto it = characters.begin(); it != characters.end(); it++){
			if(character == **it){
				characters.erase(it);
			}
		}
	}
/*
	void Environment::move_to_new_room(Character & character, Environment & env){
		for(auto it = characters.begin(); it != characters.end(); it++){
			if(character == **it){
				characters.erase(it);
				env.characters.push_back(&character);
				return;
			}
		}
		cout << "ERROR LEAVE" << endl;
		return;
	}
*/
	void Environment::enter(Character & character){
		characters.push_back(&character);
		return;
	}

	void Environment::pick_up(Object obj){
		for(auto iter = objects.begin(); iter != objects.end(); iter++){
			/*if(obj.name() == *iter.name()){
				objects.erase(iter);
				return;
			}*/
		}
		cout << "ERROR PICK_UP" << endl;
		return;
	}
	
	void Environment::drop(Object obj){
		objects.push_back(obj);
	}
};

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
		pp = e.pp;
		exits = e.exits;
		descr = e.descr;
		objects = e.objects;
		hidden_objects = e.hidden_objects;
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

	Character * Environment::is_character(string target){
		for(auto it = characters.begin(); it != characters.end(); it++){
			if((*it)->name() == target){
				return *it;
			}
		}
		return NULL;
	}

	int Environment::get_id() const{
		return id;
	}
	
	//returns the description of the current environment
	string Environment::description() const{
		return descr;
	}

	void Environment::print_characters(){
		if(characters.size() > 1){
			cout << "Current residents of " << description() << endl;
			for(unsigned int i = 0; i < characters.size(); i++){
				cout << "\t" << characters[i]->name() << endl;
			}
		} else {
			cout << "You are alone in " << description() << endl;
		}
	}
	bool Environment::set_neighbour(string direction, Environment * e){
		return exits.insert({direction, e}).second;
	}
	
	//Get a reference to the neigbour in the chosen direction
	Environment & Environment::neighbour(string direction){
		auto it = exits.find(direction);
		if(it == exits.end()){
			return *this;;
		}
		return *(it->second);
	}
		
	//Get a description of all the possible directions from the current 
	//environment
	void Environment::directions() const{
		cout << "You can move: " << endl;
		for(auto iter = exits.begin(); iter != exits.end(); iter++){
			cout << "\t" << iter->first << endl;
		}
	}
	
	void Environment::leave(Character & character){
		for(auto it = characters.begin(); it != characters.end(); it++){
			if(character == **it){
				characters.erase(it);
				if(character.is_player()){
					pp = false;
					return;
				} else {
					return;
				}
			}
		}
	}

	void Environment::enter(Character & character){
		if(character.is_player()){
			pp = true;
		}
		characters.push_back(&character);
	}

	Object * Environment::pick_up(string obj){
		for(auto it = objects.begin(); it != objects.end(); ++it){
			if((*it)->name() == obj){
				objects.erase(it);
				cout << "Picked up " << obj << "!" << endl;
				return *it;
			}
		}
		return NULL;
	}

	Object * Environment::hidden_items(){
		if(hidden_objects.size() < 0){
			return hidden_objects.front();
		}
		return NULL;
	}
	
	void Environment::drop(Object * obj){
		cout << "You dropped " << obj->description() << endl;
		objects.push_back(obj);
	}

	bool Environment::find_object(string object){
		for(auto it=objects.begin(); it != objects.end(); it++){
			if((*it)->name() == object){
				return true;
			}
		}
		return false;
	}
};

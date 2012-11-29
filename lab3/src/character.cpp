	
#include <string>
#include <iostream>
#include "character.h"
using namespace std;
	
namespace game{
	//Character::Character(string name, string type, Environment e): n(name), t(type), environ(e) {};

	bool Character::operator==(const Character & cref){
		return n == cref.name();
	}

	Character & Character::operator=(const Character & cref){
		t = cref.type();
		n = cref.name();
		hp = cref.health();
		curr_pos = cref.get_pos();
		return *this;
	}

	void Character::speak(string line){
		cout << "You say: " << line << "!" << endl;
	}
	int Character::health() const{
		return hp;
	}

	Environment * Character::get_pos() const{
		return curr_pos;
	}

	string Character::type() const{
		return t;
	}

	string Character::name() const{
		return n;
	}

	void Character::go(string direction){
		string from = curr_pos->description();
		if(curr_pos->neighbour(*curr_pos, direction)){
			curr_pos->enter(this);
			cout << "You have left " << from <<  " and entered " << curr_pos->description() << endl;
		} else {
			cout << "You can't go there.." << endl;
		}
	}

	void Character::drop(string object){
		cout << "VERE IS ZE DJ!?" << endl;
	}

	void Character::pick_up(string object){
		cout <<  "Nah..." << endl;
	}

	bool Character::action(int act){
		switch(act){
			case 0: cout << "Where?" << endl;
				return false;
			case 1: dig();
				return true;
			case 2: look();
				return false;
			case 3: cout << "Fight who?" << endl;
				return false;
			case 4: cout << "Talk to who?" << endl;
				return false;
			case 5: speak();
				return false;
			default: cout << "You cannot perform this move.." << endl;
				return false;
			}
		return false;
	}

	bool Character::action(int act, string target){
		switch(act){
			case 0: go(target);
				return true;
			case 1: dig();
				return true;
			case 2: look();
				return false;
			case 3: fight(target);
				return true;
			case 4: talk_to(target);
				return true;
			case 5: speak(target);
				return false;
			default: cout << "You cannot perform this move.." << endl;
				return false;
			}
		return false; 
	}

};

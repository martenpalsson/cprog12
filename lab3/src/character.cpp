	
#include <string>
#include <iostream>
#include "character.h"
using namespace std;
	
namespace game{
	//Character::Character(string name, string type, Environment e): n(name), t(type), environ(e) {};

	bool Character::operator==(const Character & cref){
		return n == cref.name();
	}
	
	Environment * Character::get_pos(){
		return curr_pos;
	}

	Character & Character::operator=(const Character & cref){
		t = cref.type();
		n = cref.name();
		hp = cref.health();
		curr_pos = cref.get_pos();
		player = cref.is_player();
		return *this;
	}
	
	void Character::set_pos(Environment * to){
		curr_pos = to;
	}
	bool Character::is_player() const{
		return player;
	}

	void Character::speak(string line){
		if(get_pos()->pp){
			if(is_player()){
				cout << "You";
			} else {
				cout << n;
			}
			cout << " say: " << line << "!" << endl;
		}
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
	
	//Bara spelare kan röra sig
	void Character::go(string direction){
		string from = curr_pos->description();
		curr_pos->leave(*this);
		Environment & to = curr_pos->neighbour(direction);
		if(to == *curr_pos){
			cout << "You can't go there.." << endl;
		} else {
			set_pos(&to);
			curr_pos->enter(*this);
			cout << "You have left " << from <<  " and entered " << to.description() << endl;
		}

	}

	void Character::drop(string object){
		if(get_pos()->pp){
			cout << "Dropping " << object << endl;
		}
	}

	void Character::pick_up(string object){
		cout <<  "Picking up item" << endl;
	}

	bool Character::action(int act){
		switch(act){
			case 0: if(get_pos()->pp)
					cout << "Where?" << endl;
				return false;
			case 1: dig();
				return true;
			case 2: look();
				return false;
			case 3: if(get_pos()->pp)
					cout << "Fight who?" << endl;
				return false;
			case 4: if(get_pos()->pp)
					cout << "Talk to who?" << endl;
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
				return false;
			case 5: speak(target);
				return false;
			default: cout << "You cannot perform this move.." << endl;
				return false;
			}
		return false; 
	}

};

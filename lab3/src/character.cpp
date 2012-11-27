	
#include <string>
#include <iostream>
#include "character.h"
using namespace std;
	
namespace game{
	//Character::Character(string name, string type, Environment e): n(name), t(type), environ(e) {};

	bool Character::operator==(const Character & cref){
		return n == cref.name();
	}
	
	string Character::type() const{
		return t;
	}

	string Character::name() const{
		return n;
	}

	void Character::go(string direction){
		Environment * env = 0;
		if(curr_pos->neighbour(env, direction)){
			curr_pos = env;
			curr_pos->enter(*this);
			cout << "You have entered " << direction << curr_pos->description() << endl;
		} else {
			cout << "You can't go there maestro" << endl;
		}
	}

	void Character::drop(string object){
		cout << "VERE IS ZE DJ!?" << endl;
	}

	void Character::pick_up(string object){
		cout <<  "Nah..." << endl;
	}

};

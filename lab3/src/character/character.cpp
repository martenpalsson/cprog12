	
#include <string>
#include <iostream>
#include "character.h"
#include "environment.h"
using namespace std;
	
namespace game{
	Character::Character(string name, string type, Environment e): n(name), t(type), environ(e) {};

	bool Character::operator==(const Character & cref){
		return n == char.name();
	}
	
	string Character::type(){
		return t;
	}

	string Character::name(){
		return n;
	}

	void Character::go(string direction){
		cout <<  "You are not really sure what to do, so you awkwardly stand there fidling with the hem of your shirt" << endl;
	}

	void Character::drop(string object){
		cout << "VERE IS ZE DJ!?" << endl;
	}

	void Character::pick_up(string object){
		cout <<  "Nah..." << endl;
	}

};

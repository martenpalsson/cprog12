#include "human.h"
#include <iostream>
#include <string>

using namespace std;

namespace game{
	
	bool Human::action(int act){
		cout << "Human takes action" << endl;
		return false;
	}
	bool Human::action(int act, string target){
		cout << "Human takes action against " << target << endl;
		return false;
	}

	void Human::look(){
		cout << "You see: " << endl;
		cout << curr_pos->description() << endl;
	}

	void Human::look(string target){
		cout << "You look at: " << target << endl;
	}

	void Human::fight(string character){
		cout << "You fight with: " << character << endl;
	}

	void Human::talk_to(string character){
		cout << character << ": " << "...." << endl;
	}
	void Human::speak(){
		cout << "HEYHEY" << endl;
	}
	Object & Human::dig(){
		cout << "You picked up an object" << endl;
		Object * obj = new Object("sak", "grej", "en fin sak", 1, 7, 900);
		return *obj;
	}
};

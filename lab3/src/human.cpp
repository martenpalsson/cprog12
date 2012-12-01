#include "human.h"
#include <iostream>
#include <string>

using namespace std;

namespace game{
	
	void Human::look(){
		bool alone = true;
		if(get_pos()->characters.size() > 1){
			alone = false;
		}
		cout << "You are ";
		if(alone){
			cout << "alone ";
		}
		cout << "in " << get_pos()->description() << endl;
		if(!alone){
			get_pos()->print_characters();
		}
		get_pos()->directions();
	}

	void Human::look(string target){
		cout << "You look at: " << target << endl;
	}

	void Human::talk_to(string character){
		cout << character << ": " << "...." << endl;
	}

	Object & Human::dig(){
		//MAINTAINERS NOTE: DANGER!
		cout << "You picked up an object" << endl;
		Object * obj = new Object("sak", "grej", "en fin sak", 1, 7, 900);
		return *obj;
	}
};

#include "human.h"
#include <iostream>
#include <string>

using namespace std;

namespace game{
	
	void Human::look(){
		cout << "You are in " << curr_pos->description() << endl;
		curr_pos->print_characters();
		curr_pos->directions();
	}

	void Human::look(string target){
		cout << "You look at: " << target << endl;
	}

	void Human::talk_to(string character){
		cout << character << ": " << "...." << endl;
	}

	Object & Human::dig(){
		cout << "You picked up an object" << endl;
		Object * obj = new Object("sak", "grej", "en fin sak", 1, 7, 900);
		return *obj;
	}
};

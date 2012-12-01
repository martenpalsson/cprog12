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
		if(get_pos()->find_object(target)){
			cout << "\tit's an object!" << endl;
		}
		if(get_pos()->is_character(target)){
			cout << "\tit's a character!" << endl;
		}
	}

	void Human::talk_to(string character){
		cout << character << ": " << "...." << endl;
	}

	void Human::dig(){
		cout << "Digging.... " << endl;
		Object * item = get_pos()->hidden_items();
		if(item != NULL){
			items.push_back(item);
			get_pos()->pick_up(item);
			return;
		}
		cout << "Nothing here.. " << endl;
	}
};

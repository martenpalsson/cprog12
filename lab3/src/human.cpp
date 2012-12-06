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

		bool items = false;
		cout << "You see ";
		if(get_pos()->objects.size() > 0)
			items = true;
		if(items){
			for(unsigned i = 0; i < get_pos()->objects.size(); ++i){
				cout << "a ";
				if(i > 0)
					cout << "\t";
				cout << get_pos()->objects[i]->name() << endl;
			}
		} else {
			cout << "no items here" << endl;
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
		Character * target = get_pos()->is_character(character);
		if(target != NULL){
			cout << "You: ";
			speak();
			cout << character << ": "; 
			target->speak();
		}
		else {
			cout << "No such character here.." << endl;
		}
	}
	
	void Human::pick_up(string object){
		if(is_player()){
			Object * obj = get_pos()->pick_up(object);
			if(obj != NULL){
				cout << "There is no such object.." << endl;
			} else {
				items.push_back(obj);
				cout << "Took " << object << endl;
			}
		}else{
			npc_action();
		}
	}

	void Human::use(string item){
		for(auto it = items.begin(); it != items.end(); ++it){
			if((*it)->name() == item){
				(*it)->event();
				return;
			}
		}
		cout << "Found no such item" << endl;
	}

	void Human::dig(){
		Object * item = get_pos()->hidden_items();
		if(item != NULL){
			items.push_back(item);
			cout << "Found: " << item->name() << endl;
			return;
		}
		cout << "Nothing here.. " << endl;
	}
};

#include "human.h"
#include <iostream>
#include <string>

using namespace std;

namespace game{
	
	void Human::look(){
		cout << get_pos()->description() << endl;
		bool alone = true;
		if(get_pos()->characters.size() > 1){
			alone = false;
		}
		if(alone){
		cout << "You are alone " << endl;
		}
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
		cout << endl;
	}

	void Human::look(string target){
		Object * obj = get_pos()->find_object(target);
		if(obj != NULL){
			cout << "You see: " << endl;
			cout << "\t" << obj->description() << endl;
			cout << endl;
			return;
		}
		Character * ch = get_pos()->is_character(target);
		if(ch != NULL){
			cout << "You look at: " << endl;
			cout << "\t" << ch->name() << endl;
			cout << endl;
			return;
		}
		cout << "Can't find " << target << ".." << endl;
		cout << endl;
	}

	void Human::talk_to(vector<string> args){
		for(string arg : args){
			Character * target = get_pos()->is_character(arg);
			if(target == NULL)
				continue;
			else{
				cout << "You (" << name() << "): ";
				speak(); 
				target->speak();
				cout << endl;
				return;
			}
		}
		cout << "No such character here.." << endl;
	}
	
	void Human::pick_up(string object){
		if(is_player()){
			Object * obj = get_pos()->pick_up(object);
			if(obj == NULL){
				cout << "There is no such object.." << endl;
			} else {
				obj->set_owner(this);
				items.push_back(obj);
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
		if(get_pos()->diggable()){
			Object * item = get_pos()->hidden_items();
			if(item != NULL){
				items.push_back(item);
				cout << "Found: " << item->name() << endl;
				return;
			}
			cout << "Nothing here.. " << endl;
		}else{
			cout << "Can't dig indoors.." << endl;
		}
	}

	void Human::print_items(){
		if(items.size() > 0){
			cout << "Your items: " << endl;
			cout << "-------------------------------" << endl;
			for(Object * item : items){
				cout << item->name() << "\t - \t" << item->description() << endl;
			}
			cout << "-------------------------------" << endl;
			cout << endl;
		} else {
			cout << "You have no items.." << endl;
			cout << endl;
		}
	}

};

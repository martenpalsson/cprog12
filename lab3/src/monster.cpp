#include "monster.h"

#include <string>
#include <iostream>

using namespace std;

namespace game{
	void Monster::dig(){
		if(get_pos()->pp){
			cout << n << " tries to dig... " << endl;
		}
	}

	void Monster::look(){
		if(get_pos()->pp){
			cout << n << " stares apathetically..." << endl;
		}
	}

	Character * Monster::spot_enemy(){
		for(Character * enemy : enemies){
			for(Character * npcs_around : get_pos()->characters){
				if(enemy->name() == npcs_around->name()){
					return enemy;
				}
			}
		}
		return NULL;
	}

	void Monster::look(string target){
		if(get_pos()->pp){
			cout << n << " stares vigorously at " << target << endl;
		}
	}

	void Monster::talk_to(vector<string> target){
		if(get_pos()->pp){
			cout << name();
			int ch = rand() % get_pos()->characters.size();
			target.push_back(get_pos()->characters[ch]->name()); 
			if(target[0] == name()){
				cout << " has a deep discussion with itself" << endl;
			} else {
				cout << " talks to " << target[0] << endl;
			}
		}
	}

	void Monster::speak(){
		if(get_pos()->pp){
			cout << name() <<  " says: Growoiwowioa!" << endl;
		}

	}

};

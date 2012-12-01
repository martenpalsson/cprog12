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

	void Monster::look(string target){
		if(get_pos()->pp){
			cout << n << " stares vigorously at " << target << endl;
		}
	}

	void Monster::talk_to(string target){
		if(get_pos()->pp){
			cout << n;
			if(target == name()){
				cout << " has a deep discussion with itself" << endl;
			} else {
				cout << " talks to " << target << endl;
			}
		}
	}

	void Monster::speak(){
		if(get_pos()->pp){
			cout << n << ": Growoiwowioa!" << endl;
		}

	}

};

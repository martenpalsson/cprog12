#include "monster.h"

#include <string>
#include <iostream>

using namespace std;

namespace game{
	Object & Monster::dig(){
		Object * obj = new Object("nått", "nått bra", "bra skit",1, 2, 3);
		if(get_pos()->pp){
			cout << n << " finds a shiny new " << obj->name() << endl;
		}
		return *obj;
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
		//BÖR KOLLA OM TARGET ÄR EN SJÄLV
		if(get_pos()->pp){
			cout << n << "talks to " << target << endl;
		}
	}

	void Monster::speak(){
		if(get_pos()->pp){
			cout << n << ": Growoiwowioa!" << endl;
		}

	}

};

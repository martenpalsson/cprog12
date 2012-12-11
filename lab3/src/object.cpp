#include <string>
#include "object.h"
#include <iostream>
using namespace std;

namespace game{
	
	Object::Object(string name, string type, string description){
		n = name;
		t = type;
		d = description;
		owner = NULL;
	}
	

	bool Object::operator==(const Object & oref){
		return n == oref.name();
	}

	string Object::name() const{
		return n;
	}

	string Object::type() const{
		return t;
	}

	string Object::description() const{
		return d;
	}

	void Object::set_owner(Character * o){
		owner = o;
	}
	void Object::event(){
		if(owner != NULL){
			if(type() == "weapon"){
				owner->set_weapon(this);
			}
			if(type() == "shield"){
				owner->set_shield(this);
			}
			if(type() == "potion"){
				owner->set_health(20);
			}
		} else {
			cout << "You don't have this item.." << endl;
		}
	}



};

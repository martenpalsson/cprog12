#include <string>
#include "object.h"
#include <iostream>
using namespace std;

namespace game{
	
	Object::Object(string name, string type, string description, int weight){
		n = name;
		t = type;
		d = description;
		w = weight;
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

	int Object::weight() const{ 
		return w;
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
		} else {
			cout << "You don't have this item.." << endl;
		}
	}



};

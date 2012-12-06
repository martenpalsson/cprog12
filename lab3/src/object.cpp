#include <string>
#include "object.h"
#include <iostream>
using namespace std;

namespace game{
	
	Object::Object(string name, int type, string description, int weight){
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

	int Object::type() const{
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
			switch(type()){
				case 0:
					cout << "svärd event" << endl;
				default:
					cout << "event körs för: " << name() << endl;
					break;
			}
		} else {
			cout << "ingen äger detta.." << endl;
		}
	}



};

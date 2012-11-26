#include <string>
#include "object.h"
#include <iostream>
using namespace std;

namespace game{
	
	Object::Object(string name, string type, string description, int weight, int volume, int price): n(name),t(type),d(description),w(weight),v(volume),p(price){}
	

	bool Object::operator==(const Object & oref){
		return n == oref.name();
	}

	string Object::name() const{
		return n;
	}

	string Object::type() const{
		return t;
	}

	void Object::description(){
		cout << d << endl;
	}

	int Object::weight(){
		return w;
	}

	int Object::volume(){
		return v;
	}

	int Object::price(){
		return p;
	}




};

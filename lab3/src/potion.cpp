#include "potion.h"
#include <string>
using namespace std;

namespace game{
	Potion::Potion(string name, string type, string description, int b):Object(name,type,description){
		owner = NULL;
		boost = b;
	}

	void Potion::event(){
		if(owner != NULL){
			owner->set_health(boost);
		}
	}

	int Potion::get_boost(){
		return boost;
	}
};

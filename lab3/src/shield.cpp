#include "shield.h"
#include <string>
using namespace std;

namespace game{
	
	Shield::Shield(string name, string type, string description, int red):Object(name,type,description){
		owner = NULL;
		reduction = red;
	}

	void Shield::event(){
		if(owner != NULL){
			owner-> set_shield(this);
		}
	}

	int Shield::get_reduction(){
		return reduction;
	}

};

#include "weapon.h"
#include <string>
using namespace std;

namespace game{

	Weapon::Weapon(string name, string type, string description, int att):Object(name,type,description){
		owner = NULL;
		damage = att;
	}

	void Weapon::event(){
		if(owner != NULL){
			owner->set_weapon(this);
		}
	}

	int Weapon::get_damage(){
		return damage;
	}
};

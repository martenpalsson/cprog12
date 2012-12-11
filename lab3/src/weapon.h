#ifndef WEAPON_H
#define WEAPON_H

#include "object.h"
#include <string>
using namespace std;

namespace game{
	struct Weapon : public Object {
		Weapon(string name, string type, string description, int att);
		int damage;
		void event();
		int get_damage();
	};
};

#endif

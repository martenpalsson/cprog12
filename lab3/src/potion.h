#ifndef POTION_H
#define POTION_H

#include "object.h"

#include <string>

using namespace std;

namespace game{
	struct Potion : public Object {
		Potion(string name, string type, string description, int boost);
		int boost;
		void event();
		int get_boost();
	};
};

#endif

#ifndef SHIELD_H
#define SHIELD_H

#include "object.h"
#include <string>
using namespace std;

namespace game{
	struct Shield : public Object {
		Shield(string name, string type, string description, int red);
		int reduction;
		void event();
		int get_reduction();
	};
};

#endif

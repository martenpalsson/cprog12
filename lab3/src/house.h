#ifndef HOUSE_H
#define HOUSE_H

#include "environment.h"
#include <string>
#include <iostream>

using namespace std;
namespace game{
	struct House : public Environment {

		House(string description, int id);

		void look(string direction);
		int huntability();
		bool dig(Object & container);
	};
};
#endif

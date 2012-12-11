#ifndef HOUSE_H
#define HOUSE_H

#include "environment.h"
#include <string>
#include <iostream>

using namespace std;
namespace game{
	struct House : public Environment {
		bool dig;
		House(string description, int id);
		
		bool diggable();
		void look(string direction);
	};
};
#endif

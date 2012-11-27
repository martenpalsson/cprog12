#ifndef FOREST_H
#define FOREST_H

#include "environment.h"
#include <string>
#include <iostream>

using namespace std;
namespace game{
	struct Forest : public Environment {

		Forest(string description, int id);
		bool dig(Object & container);
		void look(string direction);
		int huntability();
	};
};
#endif

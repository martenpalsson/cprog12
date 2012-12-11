#ifndef FOREST_H
#define FOREST_H

#include "environment.h"
#include <string>
#include <iostream>

using namespace std;
namespace game{
	struct Forest : public Environment {
		bool dig;
		Forest(string description, int id);
		bool diggable();
		void look(string direction);
	};
};
#endif

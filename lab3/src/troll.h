#ifndef TROLL_H
#define TROLL_H

#include "monster.h"

using namespace std;

namespace game{
	struct Troll : public Monster{
		Troll(string name, int health, Environment * env, bool p);
		Troll(string name, Environment * env);
		void fight(string target);
		
	};
};

#endif

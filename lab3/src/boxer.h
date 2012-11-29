#ifndef BOXER_H
#define BOXER_H

#include "human.h"
#include <iostream>
#include <string>
using namespace std;

namespace game{
	struct Boxer: public Human{
		Boxer(string name, int health, Environment * e, bool p);
		Boxer(string name, Environment * e); //För npc
		void fight(string character);
		void speak();
	};


};
#endif

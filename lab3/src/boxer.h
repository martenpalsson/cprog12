#ifndef BOXER_H
#define BOXER_H

#include "human.h"
#include <iostream>
#include <string>
using namespace std;

namespace game{
	struct Boxer: public Human{
		Boxer(string name, int health, Environment * e);
		Boxer(string name, Environment * e); //För npc
		bool action(int act);
		bool action(int act, string target);
		void fight(string character);
		void talk_to(string character);
		void speak();
	};


};
#endif

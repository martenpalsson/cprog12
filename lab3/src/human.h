#ifndef HUMAN_H
#define HUMAN_H

#include "character.h"
#include <iostream>
#include <string>
using namespace std;

namespace game {
	struct Human : public Character {
		virtual void action();
		virtual void fight(string character);
		virtual void talk_to(string character);
		virtual void speak();
	};
};

#endif

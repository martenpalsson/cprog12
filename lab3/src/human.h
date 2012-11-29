#ifndef HUMAN_H
#define HUMAN_H

#include "object.h"
#include "character.h"
#include <iostream>
#include <string>
using namespace std;

namespace game {
	struct Human : public Character {
		
		Object & dig();
		void look();
		void look(string target);

		virtual void talk_to(string character);

		virtual void fight(string character) = 0;
		virtual void speak() = 0;
	};
};

#endif

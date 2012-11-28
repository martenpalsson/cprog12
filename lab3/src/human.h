#ifndef HUMAN_H
#define HUMAN_H

#include "object.h"
#include "character.h"
#include <iostream>
#include <string>
using namespace std;

namespace game {
	struct Human : public Character {
		virtual bool action(int act);
		virtual bool action(int act, string target);
		virtual void fight(string character);
		virtual void talk_to(string character);
		virtual void speak();
		Object & dig();
		void look();
		void look(string target);
	};
};

#endif

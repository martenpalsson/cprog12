#ifndef MONSTER_H
#define MONSTER_H

#include "character.h"

#include <string>

using namespace std;

namespace game{
	struct Monster : public Character {
		Object & dig();
		void look();
		void look(string target);

		virtual void talk_to(string target);
		virtual void speak();
		
		virtual void fight(string target) = 0;
	};
};

#endif

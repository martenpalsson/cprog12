#ifndef MONSTER_H
#define MONSTER_H

#include "character.h"
#include <vector>
#include <string>

using namespace std;

namespace game{
	struct Monster : public Character {
		vector<Character*> enemies;
		void dig();
		void look();
		void look(string target);
		Character * spot_enemy();

		virtual void talk_to(vector<string> target);
		virtual void speak();
		
		virtual void fight(string target) = 0;
	};
};

#endif

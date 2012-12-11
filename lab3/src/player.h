#ifndef PLAYER_H
#define PLAYER_H

#include "human.h"
#include <iostream>
#include <string>
using namespace std;

namespace game{
	struct Player: public Human{
		bool dead;
		Player(string name, int health, Environment * e, bool p);
		Player(string name, Environment * e); //För npc
		void fight(string character);
		void speak();
		void die();
		bool take_damage(Character * enemy, int damage);
		Object * find_item(string name);
		Character * spot_enemy();
	};


};
#endif

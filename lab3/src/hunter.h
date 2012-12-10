#include "monster.h"
#include <string>

using namespace std;

namespace game {
	struct Hunter : public Monster {
		Hunter(string name, int health, Environment * e, Character * enemy);
		void fight(string target);
		bool take_damage(Character * enemy, int at);
		void die();
	};
};


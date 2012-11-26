#ifndef CHARACTER_H
#define CHARACTER_H
	
#include <string>
#include "environment.h"
using namespace std;

namespace game {
	struct Character{
		string n;
		string t;
		Environment * environ;

		Character(string name, string type, Environment * e);

		string type() const;
		string name() const;
		void go(string direction);
		void drop(string object);
		void pick_up(string object);
		bool operator==(const Character & cref);

		virtual void action() = 0;
		virtual void fight(string character) = 0;
		virtual void talk_to(string character) = 0;

	};
};

#endif

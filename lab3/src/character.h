#ifndef CHARACTER_H
#define CHARACTER_H
	
#include <string>
#include "environment.h"
#include "object.h"
using namespace std;

class Environment;
namespace game {
	struct Character{
		int hp;
		string n;
		string t;
		Environment * curr_pos;

//		Character(string name, string type, int health, Environment * e);

		string type() const;
		string name() const;
		void go(string direction);
		void drop(string object);
		void pick_up(string object);
		bool operator==(const Character & cref);

		virtual bool action(int act) = 0;
		virtual bool action(int act, string target) = 0;
		virtual void fight(string character) = 0;
		virtual void talk_to(string character) = 0;
		virtual void speak() = 0;
	};
};

#endif

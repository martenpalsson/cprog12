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
		bool player;

//		Character(string name, string type, int health, Environment * e);
		bool is_player() const;
		string type() const;
		string name() const;
		int health() const;
		Environment * get_pos() const;

		bool operator==(const Character & cref);
		Character & operator=(const Character & cref);

		void go(string direction);
		void speak(string line);
		void drop(string object);
		void pick_up(string object);
		bool action(int act);
		bool action(int act, string target);
		virtual Object & dig() = 0;
		virtual void look() = 0;
		virtual void look(string target) = 0;
		virtual void fight(string character) = 0;
		virtual void talk_to(string character) = 0;
		virtual void speak() = 0;
	};
};

#endif

#ifndef CHARACTER_H
#define CHARACTER_H
	
#include <string>
#include "environment.h"
#include "object.h"
using namespace std;

namespace game {
class Environment;
	struct Character{
	private:
		Environment * curr_pos;
	public:
		int hp;
		string n;
		string t;
		bool player;

//		Character(string name, string type, int health, Environment * e);
		bool is_player() const;
		string type() const;
		string name() const;
		int health() const;
		Environment * get_pos() const;

		void npc_action();
		bool operator==(const Character & cref);
		Character & operator=(const Character & cref);
		void set_pos(Environment * to);
		void go(string direction);
		Environment * get_pos();
		void speak(string line);
		void drop(string object);
		bool action(int act);
		bool action(int act, string target);
		virtual void dig() = 0;
		virtual void look() = 0;
		virtual void look(string target) = 0;
		virtual void fight(string character) = 0;
		virtual void talk_to(string character) = 0;
		virtual void speak() = 0;
		virtual void pick_up(string target);
		virtual void use(string item);
	};
};

#endif

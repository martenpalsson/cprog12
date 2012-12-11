#ifndef CHARACTER_H
#define CHARACTER_H
	
#include <string>
#include <vector>
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
		bool alive;
		string n;
		string t;
		bool player;
		Object * weapon;
		Object * shield;

//		Character(string name, string type, int health, Environment * e);
		bool is_player() const;
		string type() const;
		Object * get_shield() const;
		Object * get_weapon() const;
		string name() const;
		int health() const;
		bool is_alive() const;
		Environment * get_pos() const;

		void npc_action();
		bool operator==(const Character & cref);
		Character & operator=(const Character & cref);
		void set_pos(Environment * to);
		void set_weapon(Object * weapon);
		bool attack(Character * enemy);
		void set_shield(Object * shield);
		void set_health(int modifier);
		void go(string direction);
		Environment * get_pos();
		void speak(string line);
		void drop(string object);
		void get_status();
		virtual void dig() = 0;
		virtual void die() = 0;
		virtual void look() = 0;
		virtual void look(string target) = 0;
		virtual Character * spot_enemy() = 0;
		virtual void fight(string character) = 0;
		virtual void talk_to(vector<string> character) = 0;
		virtual void speak() = 0;
		virtual bool take_damage(Character * enemy,int damage) = 0;
		virtual void pick_up(string target);
		virtual void use(string item);
		virtual void print_items();
		virtual Object * find_item(string name);
	};
};

#endif

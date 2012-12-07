#ifndef HUMAN_H
#define HUMAN_H

#include "object.h"
#include "character.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace game {
	struct Human : public Character {
		vector<Object*> items;
		void dig();
		void look();
		void look(string target);

		void pick_up(string item);
		void use(string item);
		void print_items();

		virtual void talk_to(vector<string> character);
		virtual void fight(string character) = 0;
		virtual void speak() = 0;
	};
};

#endif

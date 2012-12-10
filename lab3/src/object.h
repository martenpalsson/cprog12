#ifndef OBJECT_H
#define OBJECT_H
#include "character.h"
#include "environment.h"
#include <string>
using namespace std;

namespace game{
	class Character;
	struct Object{
		string n;
		string t;
		string d;
		int w;
		Character * owner;

		Object(string name, string type, string description, int weight);
		bool operator==(const Object & oref);
		string name() const;
		string type() const;
		string description() const;
		int weight() const;
		void set_owner(Character * o);
		virtual void event();
	};
};
#endif

#ifndef ENVIRON_H
#define ENVIRON_H
#include "character.h"
#include "object.h"
#include <string>
#include <map>
#include <vector>

using namespace std;
namespace game {
	class Object;
	class Character;
	struct Environment{
		
		Environment & operator=(const Environment & e);
		bool operator==(const Environment & env);
		
		int id;
		bool dig;
		bool pp;
		string n;
		string descr;
		vector<Object*> objects;
		vector<Character*> characters;
		vector<Object*> hidden_objects;
		map<string, Environment*> exits;

		void set_description(string description);
		void print_characters() const;
		void directions() const;
		void enter(Character & character);
		void leave(Character & character);
		void drop(Object * obj);
		bool set_neighbour(string dir, Environment * env);
		int get_id() const;
		string name() const;
		string description() const;
		Object * hidden_items();
		Object * pick_up(string object);
		Object * find_object(string object) const;
		Character * is_character(string target) const;
		Environment & neighbour(string direction);
		virtual void look(string direction) = 0;
		virtual bool diggable() = 0;
	};
};
		
#endif

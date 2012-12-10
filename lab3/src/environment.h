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
		
		bool pp;
		Environment & operator=(const Environment & e);
		//Environment(string description, int id);
		bool operator==(const Environment & env);
		
		vector<Object*> hidden_objects;
		map<string, Environment*> exits;
		string n;
		string descr;
		vector<Object*> objects;
		vector<Character*> characters;
		int id;

		Object * hidden_items();
		Character * is_character(string target);
		Object * find_object(string object);
		void print_characters();
		int get_id() const;
		string name() const;
		void set_description(string description);
		string description() const;
		bool set_neighbour(string dir, Environment * env);
		Environment & neighbour(string direction);
		void directions() const;
		void enter(Character & character);
		void leave(Character & character);
		Object * pick_up(string object);
		void drop(Object * obj);
		virtual int huntability() = 0;
		virtual void look(string direction) = 0;
		virtual bool dig(Object & container) = 0;
	};
};
		
#endif

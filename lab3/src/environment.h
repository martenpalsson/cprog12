#ifndef ENVIRON_H
#define ENVIRON_H
#include "character.h"
#include "object.h"
#include <string>
#include <map>
#include <vector>

using namespace std;
namespace game {
	class Character;
	struct Environment{
		
		bool pp;
		Environment & operator=(const Environment & e);
		//Environment(string description, int id);
		bool operator==(const Environment & env);
		
		map<string, Environment*> exits;
		string descr;
		vector<Object> objects;
		vector<Character*> characters;
		int id;

		void print_characters();
		int get_id() const;
		string description() const;
		bool set_neighbour(string dir, Environment * env);
		bool neighbour(Environment & env, string direction);
		void directions() const;
		void enter(Character * character);
		void leave(Character & character);
		void pick_up(Object obj);
		void drop(Object obj);
		virtual int huntability() = 0;
		virtual void look(string direction) = 0;
		virtual bool dig(Object & container) = 0;
	};
};
		
#endif

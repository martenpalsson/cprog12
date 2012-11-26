#ifndef ENVIRON_H
#define ENVIRON_H
#include <string>
#include <map>
#include <vector>

using namespace std;
namespace game {
	struct Environment{
		map<string, Environment> exits;
		string descr;
		vector<Object> objects;
		vector<Character> characters;

		string description();
		Environment & neighbour(string direction);
		void directions();
		void enter(Character character);
		void leave(Character character);
		void pick_up(Object obj);
		void drop(Object obj);
	};
};
		
#endif

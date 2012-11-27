#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using namespace std;

namespace game{
	struct Object{
		string n;
		string t;
		string d;
		int w;
		int v;
		int p;

		Object(string name, string type, string description, int weight, int volume, int price);
		bool operator==(const Object & oref);
		string name() const;
		string type() const;
		void description();
		int weight();
		int volume();
		int price();
	};
};
#endif

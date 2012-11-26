#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using namespace std;

extern string TEST;

void print(string a);

struct Object{
	string name;
	string type;

	Object(string n, string t): name(n),type(t) {};

};
#endif

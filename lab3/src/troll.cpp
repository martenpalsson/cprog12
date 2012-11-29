#include "troll.h"

#include <string>
#include <iostream>

using namespace std;

namespace game{
	Troll::Troll(string name, int health, Environment * e, bool p){
		n = name;
		hp = health;
		curr_pos = e;
		t = "troll";
		player = p;
	}

	Troll::Troll(string name, Environment * e){
		n = name;
		srand(time(NULL));
		hp = (rand() % 30) + 10;
		t = "troll";
		curr_pos = e;
		player = false;
	}
	
	void Troll::fight(string target){
		if(curr_pos->pp){
			cout << n << " fights " << target << endl;
		}
	}
};

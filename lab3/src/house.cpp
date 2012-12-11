#include "house.h"
#include <iostream>
#include <string>

using namespace std;
namespace game {
	
	House::House(string name, int id2){
		id = id2;
		n = name;
		dig = false;
	}
	
	void House::look(string direction){
		//Environment * env = 0;
		//neighbour(env,direction);
		//cout << "You see: " << env->description() << endl;
	}

	bool House::diggable(){
		return dig;
	}

};


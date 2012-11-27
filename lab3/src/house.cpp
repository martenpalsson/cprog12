#include "house.h"
#include <iostream>
#include <string>

using namespace std;
namespace game {
	
	House::House(string description, int id2){
		id = id2;
		descr = description;
	}
	
	void House::look(string direction){
		Environment * env = 0;
		neighbour(env,direction);
		cout << "You see: " << env->description() << endl;
	}
	int House::huntability(){
		return 0;
	}

	bool House::dig(Object & container){
		cout << "Can't dig here" << endl;
		return false;
	}
};


#include "house.h"
#include <iostream>
#include <string>

using namespace std;
namespace game {
	
	House::House(string name, int id2){
		id = id2;
		n = name;
	}
	
	void House::look(string direction){
		//Environment * env = 0;
		//neighbour(env,direction);
		//cout << "You see: " << env->description() << endl;
	}
	int House::huntability(){
		return 0;
	}

	bool House::dig(Object & container){
		cout << "Can't dig here" << endl;
		return false;
	}
};


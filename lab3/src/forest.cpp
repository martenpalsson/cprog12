#include "forest.h"
#include <iostream>
#include <string>

using namespace std;
namespace game {
	
	Forest::Forest(string description, int id2){
		id = id2;
		descr = description;
	}
	
	void Forest::look(string direction){
		cout << "You see nothing" << endl;
	}
	
	bool Forest::dig(Object & container){
		cout << "You found nothing" << endl;
		return false;
	}

	int Forest::huntability(){
		return 10;
	}
};


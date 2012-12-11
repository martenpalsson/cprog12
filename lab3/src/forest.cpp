#include "forest.h"
#include <iostream>
#include <string>

using namespace std;
namespace game {
	
	Forest::Forest(string name, int id2){
		id = id2;
		n = name;
		dig = true;
	}
	
	void Forest::look(string direction){
		cout << "You see nothing" << endl;
	}
	bool Forest::diggable(){
		return dig;
	}
	

};


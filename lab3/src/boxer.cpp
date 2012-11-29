#include "boxer.h"
#include <string>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

namespace game{

	
	Boxer::Boxer(string name, int health, Environment * e){
		n = name;
		hp = health;
		curr_pos = e;
		t = "boxer";
	}

	Boxer::Boxer(string name, Environment * e){
		n = name;
		srand(time(NULL));
		hp = (rand() % 30) + 10;
		t = "boxer";
		curr_pos = e;
	}

	void Boxer::fight(string character){
		cout << "You fight with " << character << endl;
	}

	void Boxer::speak(){
		cout << "Heyhey" << endl;
	}
};

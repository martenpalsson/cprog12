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

	bool Boxer::action(int act){
		switch(act){
			case 1: cout << "Where?" << endl;
				return false;
			case 2: dig();
				return true;
			case 3: look();
				return false;
			case 4: cout << "Fight who?" << endl;
				return false;
			case 5: cout << "Talk to who?" << endl;
				return false;
			case 6: speak();
				return false;
			default: cout << "You cannot perform this move.." << endl;
				return false;
			}
		return false;
	}

	bool Boxer::action(int act, string target){
		switch(act){
			case 1: move(target);
				return true;
			case 2: dig();
				return true;
			case 3: look();
				return false;
			case 4: fight(target);
				return true;
			case 5: talk_to(target);
				return true;
			case 6: speak();
				return false;
			default: cout << "You cannot perform this move.." << endl;
				return false;
			}
		return false; 
	}

	void Boxer::fight(string character){
		cout << "You fight with " << character << endl;
	}

	void Boxer::talk_to(string character){
		cout << "You talk to " << character << endl;
	}

	void Boxer::speak(){
		cout << "Heyhey" << endl;
	}
};

#include "human.h"
#include <iostream>
#include <string>

using namespace std;

namespace game{
	
	void Human::action(){
		cout << "Human takes action" << endl;
	}

	void Human::fight(string character){
		cout << "You fight with: " << character << endl;
	}

	void Human::talk_to(string character){
		cout << character << ": " << "...." << endl;
	}
	void Human::speak(){
		cout << "HEYHEY" << endl;
	}
};

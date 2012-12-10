#include "troll.h"

#include <string>
#include <iostream>

using namespace std;

namespace game{
	Troll::Troll(string name, int health, Environment * e, bool p){
		n = name;
		hp = health;
		set_pos(e);
		t = "troll";
		player = p;
		alive = true;
	}

	Troll::Troll(string name, Environment * e){
		n = name;
//		srand(time(NULL));
		hp = (rand() % 30) + 10;
		t = "troll";
		set_pos(e);
		player = false;
		alive = true;
	}
	

	void Troll::fight(string target){
		if(get_pos()->pp){
			Character * enemy = get_pos()->is_character(target);
			cout << n << " attacks " << enemy->name() << "!" << endl;
			attack(enemy);
		}
	}

	Character * Troll::choose_target(){
		int t = rand() % get_pos()->characters.size();
		Character * target = get_pos()->characters[t];
		return target;
	}

	void Troll::die(){
		cout << "Nu körs die i troll" << endl;
		get_pos()->leave(*this);
		delete this;
	}

	bool Troll::take_damage(Character * enemy, int attack_power){
		enemies.push_back(enemy);
		int defense = 5;
		int damage = attack_power-defense;
		if(damage < 1){
			cout << name() << " blocked the attack!" << endl;
		}else{
			cout << enemy->name() << " hit " << name() << " for " << damage << " damage!" << endl;
		}
		hp -= damage;
		if(health() <= 0){
			cout << name() << " died!" << endl;
			alive = false;
			return true;
		}
		return false;
	}
};

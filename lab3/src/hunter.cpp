#include "hunter.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace game{
	Hunter::Hunter(string name, int health, Environment * env, Character * enemy){
		hp = health;
		n = name;
		set_pos(env);
		alive = true;
		weapon = new Object("Bow", "bow", "a fine bow", 40);
		shield = NULL;
		player = false;
		t = "hunter";
		enemies.push_back(enemy);
	}

	void Hunter::fight(string target){
		if(get_pos()->pp){
			Character * enemy = get_pos()->is_character(target);
			cout << n << " attacks " << enemy->name() << "!" << endl;
			attack(enemy);
		}
	}
	bool Hunter::take_damage(Character * enemy, int attack_power){
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
	void Hunter::die(){
		get_pos()->leave(*this);
		delete this;
	}
};


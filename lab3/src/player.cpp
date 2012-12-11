#include "player.h"
#include <string>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

namespace game{

	
	Player::Player(string name, int health, Environment * e, bool p){
		n = name;
		hp = health;
		set_pos(e);
		t = "player";
		player = p;
		shield = NULL;
		weapon = NULL;
		alive = true;
	}

	Player::Player(string name, Environment * e){
		n = name;
		srand(time(NULL));
		hp = (rand() % 30) + 10;
		t = "player";
		set_pos(e);
		player = false;
		weapon = NULL;
		shield = NULL;
		alive = true;
	}

	void Player::fight(string character){
		Character * enemy = get_pos()->is_character(character);
		if(enemy != NULL){
			cout << "You attack " << enemy->name() << "!" << endl;
			bool victory = attack(enemy);
			if(victory){
				cout << "You defeated " << enemy->name() << "!" << endl;
			} 
		}
	}
	
	Object * Player::find_item(string name){
		for(auto it = items.begin(); it != items.end(); it++){
			if((*it)->name() == name){
				return *it;
			}
		}
		return NULL;
	}

	bool Player::take_damage(Character * enemy,int attack_power){
		int defense = 0;
		if(get_shield() != NULL)
			defense += 10;
		int damage = attack_power-defense;
		if(damage < 1){
			cout << "You blocked the attack!" << endl;
		} else {
			cout << enemy->name() << " hit you for " << damage << " damage!" << endl;
		}
		hp -= damage;
		if(health() <= 0){
			cout << "You died!" << endl;
			alive = false;
			return true;
		}
		return false;
	}

	void Player::die(){
		alive = false;
	}

	void Player::speak(){
		cout << "Heyhey" << endl;
	}
	Character * Player::spot_enemy(){
		return NULL;
	}
};

	
#include <string>
#include <iostream>
#include <vector>
#include "character.h"
using namespace std;
	
namespace game{
	//Character::Character(string name, string type, Environment e): n(name), t(type), environ(e) {};

	bool Character::operator==(const Character & cref){
		return n == cref.name();
	}
	
	Environment * Character::get_pos(){
		return curr_pos;
	}

	Character & Character::operator=(const Character & cref){
		t = cref.type();
		weapon = cref.get_weapon();
		shield = cref.get_shield();
		n = cref.name();
		hp = cref.health();
		curr_pos = cref.get_pos();
		player = cref.is_player();
		alive = cref.is_alive();
		return *this;
	}
	void Character::set_health(int modifier){
		hp += modifier;
	}
	
	void Character::set_pos(Environment * to){
		curr_pos = to;
	}
	bool Character::is_player() const{
		return player;
	}
	
	Object * Character::find_item(string name){
		return NULL;
	}

	Object * Character::get_weapon() const{
		return weapon;
	}
	Object * Character::get_shield() const{
		return shield;
	}

	void Character::set_weapon(Object * object){
		cout << "Equipped " << object->name() << endl;
		weapon = object;
	}

	void Character::set_shield(Object * obj){
		cout << "Equipped " << obj->name() << endl;
		shield = obj;
	}
	void Character::speak(string line){
		if(get_pos()->pp){
			if(is_player()){
				cout << "You";
			} else {
				cout << n;
			}
			cout << " say: " << line << "!" << endl;
		}
	}
	int Character::health() const{
		return hp;
	}

	Environment * Character::get_pos() const{
		return curr_pos;
	}

	string Character::type() const{
		return t;
	}

	string Character::name() const{
		return n;
	}
	
	void Character::go(string direction){
		string npc_direction;
		if(!is_player()){
			int dir = rand() % curr_pos->exits.size();
			int i = 0;
			for(auto it = curr_pos->exits.begin(); it != curr_pos->exits.end(); ++it){
				if(i == dir)
					npc_direction = it->first;
				i++;
			}
		}
		string from = curr_pos->name();
		curr_pos->leave(*this);
		Environment & to = curr_pos->neighbour(direction);
		if(to == *curr_pos){
			if(!is_player()){
				Environment & npc_to = curr_pos->neighbour(npc_direction); 
				if(npc_to == *curr_pos){
					curr_pos->enter(*this);
					cout << "NPC can't go there.." << endl;
					return;
				}else{
					set_pos(&npc_to);
					curr_pos->enter(*this);
					return;

				}
			} else {
				curr_pos->enter(*this);
				cout << "You can't go there.." << endl;
				return;
			}
		}
		set_pos(&to);
		curr_pos->enter(*this);
		cout << "You have left " << from <<  " and entered " << to.name() << endl;
	}

	
	
	void Character::get_status(){
		cout << "--------------------------------" << endl;
		cout << "Name:  " << name() << endl;
		cout << "Health: " << health() << endl;
		if(get_weapon() != NULL)
			cout << "Weapon: " << get_weapon()->name() << endl;
		else 
			cout << "Weapon: None" << endl;
		if(get_shield() != NULL)
			cout << "Shield: " << get_shield()->name() << endl;
		else 
			cout << "Shield: None" << endl;
		cout << "Current position: " << get_pos()->name() << endl;
		cout << "--------------------------------" << endl;
		cout << endl;
	}
	
	void Character::drop(string object){
		if(get_pos()->pp){
			cout << "Dropping " << object << endl;
		}
	}

	bool Character::attack(Character * enemy){
		int damage;
		if(!is_player()){
			damage = 10;
			if(get_weapon() != NULL){
				damage += 20;
			}
		}else{
			damage = 5;
			if(get_weapon() != NULL)
				damage += 20;
		}
		bool defeated = enemy->take_damage(this,damage);
		if(defeated){
			return true;
		}else{
			return false;
		}
	}


	void Character::npc_action(){
		cout << "npc action" << endl;
	}

	void Character::pick_up(string object){
		npc_action();
	}

	void Character::use(string item){
		npc_action();
	}

	bool Character::is_alive() const{
		return alive;
	}
	
	void Character::print_items(){
		npc_action();
	}

};

	
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
		att = cref.attack();
		def = cref.defense();
		n = cref.name();
		hp = cref.health();
		curr_pos = cref.get_pos();
		player = cref.is_player();
		return *this;
	}
	
	void Character::set_pos(Environment * to){
		curr_pos = to;
	}
	bool Character::is_player() const{
		return player;
	}

	int Character::attack() const{
		return att;
	}
	int Character::defense() const{
		return def;
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
	
	//Bara spelare kan röra sig, FIXA
	void Character::go(string direction){
		string npc_direction;
		if(!is_player()){
			cout << "npc i move" << endl;
			int dir = rand() % curr_pos->exits.size();
			int i = 0;
			for(auto it = curr_pos->exits.begin(); it != curr_pos->exits.end(); ++it){
				if(i == dir)
					npc_direction = it->first;
				i++;
			}
		}
		
		string from = curr_pos->description();
		curr_pos->leave(*this);
		Environment & to = curr_pos->neighbour(direction);
		if(to == *curr_pos){
			if(!is_player()){
				to = curr_pos->neighbour(npc_direction);
				if(to == *curr_pos){
					curr_pos->enter(*this);
					cout << "NPC can't go there.." << endl;
				}else{
					set_pos(&to);
					curr_pos->enter(*this);
					cout << "NPC have left " << from <<  " and entered " << to.description() << endl;

				}
			} else {
				curr_pos->enter(*this);
				cout << "You can't go there.." << endl;
			}
		}
		set_pos(&to);
		curr_pos->enter(*this);
		cout << "You have left " << from <<  " and entered " << to.description() << endl;
	}

	
	
	void Character::get_status(){
		cout << "--------------------------------" << endl;
		cout << "Name:  " << name() << endl;
		cout << "Health: " << health() << endl;
		cout << "Attack: " << attack() << endl;
		cout << "Defense: " << defense() << endl;
		cout << "Current position: " << get_pos()->description() << endl;
		cout << "--------------------------------" << endl;
	}

	void Character::drop(string object){
		if(get_pos()->pp){
			cout << "Dropping " << object << endl;
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
	
	void Character::print_items(){
		npc_action();
	}

};

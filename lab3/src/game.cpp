#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "game.h"

#define EXIT 8

using namespace std;
using namespace game;

int main(){
	srand(time(NULL));
	vector<Environment*> map;
	vector<Character*> npc;
	Parser parser;
	Environment * start;
	init_game(parser,npc,start,map);
	parser.init_cmds(parser.cmds);
	parser.intro();
	vector<string> tokens;
	string command = "";
	Character * player = npc.front();

	while(true){
		bool pf = false;
		while(!pf){
			tokens.clear();
			cout << player->get_pos()->name() << ">";
			getline(cin,command);
			if(command == "exit"){
				cout << "byebye" << endl;
				return 0;
			}
			split_line(tokens, command);
			pf = parser.parse_cmd(player,tokens);
		}
		//Här utför npc:erna sina moves
		gen_npc_actions(npc,parser);
		cout << endl;
		if(!(player->is_alive())){
			cout << "Game Over" << endl;
			return 0;
		}else{
			if(player->find_item("Graal") != NULL){
				cout << "You have found a nice Graal, well done!" << endl;
				break;
			}

		}
	}
	cout << "Game over!" << endl;
	return 0;
}
	
void init_map(Environment * & start, vector<Environment*> & map){
	House * home = new House("Home",0);
	Forest * forest = new Forest("Forest",1);
	Forest * western_forest = new Forest("Western Forest",2);
	House * old_house = new House("Old House",3);
	Forest * hidden_room = new Forest("Secret room", 4);
	House * castle = new House("Castle", 5);

	home->set_neighbour("east", forest);
	home->set_neighbour("north", western_forest);
	forest->set_neighbour("west", home);
	forest->set_neighbour("north", old_house);
	forest->set_neighbour("east", castle);
	western_forest->set_neighbour("east", old_house);
	western_forest->set_neighbour("south", home);
	western_forest->set_neighbour("west", hidden_room);
	old_house->set_neighbour("west", western_forest);
	old_house->set_neighbour("south", forest);
	hidden_room->set_neighbour("east", home);
	castle->set_neighbour("west", forest);

	home->set_description("This is your home");
	forest->set_description("This is a fine forest");
	western_forest->set_description("It's a dense and dark forest, it's difficult to see anything");
	old_house->set_description("An old house, seems abandoned..");
	castle->set_description("A standard castle");

	map.push_back(home);
	map.push_back(forest);
	map.push_back(western_forest);
	map.push_back(old_house);
	map.push_back(castle);
	map.push_back(hidden_room);
	start = home;
}


	void init_game(Parser parser,vector<Character*> & npc,Environment * & start,vector<Environment*> & map){
		read_file();
		init_map(start,map);
		init_player(npc, parser, start);
		init_chars(npc,start,map);
		init_objects(map);
		return;
	}

	bool read_file(){
		string line;
		ifstream file("default.txt");
		if(file.is_open()){
			while(file.good()){
				getline(file,line);
				cout << line << endl;
			}
			file.close();
		}else{
			cout << "Can't open file.." << endl;
			return false;
		}
		return true;
	}

	void init_objects(vector<Environment*> & map){
		Object * graal = new Object("Graal", "object", "A fine Graal");
		Object * sword = new Weapon("Sword", "weapon", "A fine sword", 10);
		Object * shield = new Shield("Shield", "shield", "A fine shield", 10);
		Object * apple = new Potion("Apple", "potion", "A fine apple", 40);
		Object * badass_sword = new Weapon("Badass Sword", "weapon", "A fine badass sword", 30);
		map[1]->drop(sword);
		map[3]->drop(shield);
		map[4]->drop(apple);
		map[2]->hidden_objects.push_back(badass_sword);
		map[5]->hidden_objects.push_back(graal);
	}

	void random_insert(Character & ch, vector<Environment*>& map){
		int room = rand() % map.size();
		ch.get_pos()->leave(ch);
		ch.set_pos(map[room]);
		map[room]->enter(ch);
	}

	void init_chars(vector<Character*> & npc, Environment * start,vector<Environment*> & map){
		Character * trolle = new Troll("Trolle", start);
		Character * trolla = new Troll("Trolla", start);
		Character * hunter = new Hunter("Hunter", 40, start, npc.front());
		random_insert(*trolle,map);
		random_insert(*trolla,map);
		random_insert(*hunter,map);
		npc.push_back(trolle);
		npc.push_back(trolla);
		npc.push_back(hunter);
	}

	void gen_npc_actions(vector<Character*> & npcs, Parser parser){
		vector<string> allowed_actions = {"say","move","talk","look"};
		vector<string> tokens;
		int action;
		for(auto it = npcs.begin(); it != npcs.end(); ++it){
			Character * npc = *it;
			if(npc->is_player()){
				continue;
			}
			if(!(npc->is_alive())){
					npcs.erase(it);
					npc->die();
					return;
			}
			Character * enemy = npc->spot_enemy();
			if(enemy != NULL){
				tokens.push_back("fight");
				tokens.push_back(enemy->name());
				parser.parse_cmd(npc, tokens);
				tokens.clear();
			}else{
				if(npc->type() == "hunter"){
					tokens.push_back("move");
				}else{
					action = rand() % allowed_actions.size();
					tokens.push_back(allowed_actions[action]);
				}
				parser.parse_cmd(npc,tokens);
				tokens.clear();
			}
		}
		return;
	}

	void split_line(vector<string> & tokens,string cmd){
			istringstream iss(cmd);
			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); 
	}

	void init_player(vector<Character*> & npc, Parser & parser, Environment * & start){
		cout << "Choose name" << endl << ">";
		string name;
		getline(cin,name);
		Player * player = new Player(name, 100, start, true);
		npc.push_back(player);
		start->enter(*player);
		cout << endl;
		return;
	}

	bool  global_speak(Character * character, string line){
		if(line == "")
			character->speak();
		else
			character->speak(line);
		return false;
	}
	
	bool global_talk_to(Character * character, string npc){
		vector<string> toks;
		split_line(toks,npc);
		character->talk_to(toks);
		return false;
	}
	bool global_move(Character * character, string direction){
		character->go(direction);
		return true;
	}
	bool global_pick_up(Character * character, string item){
		character->pick_up(item);
		return true;
	}
	bool global_look(Character * character, string a){
		if(a == "")
			character->look();
		else
			character->look(a);
		return false;
	}
	bool global_fight(Character * character, string target){
		character->fight(target);
		return true;
	}
	bool global_inv(Character * character, string a){
		character->print_items();
		return false;
	}
	
	bool global_status(Character * character, string a){
		character->get_status();
		return false;
	}
	bool global_drop(Character * character, string item){
		character->drop(item);
		return true;
	}
	
	bool global_dig(Character * character, string a){
		character->dig();
		return true;
	}
	bool global_use(Character * character, string item){
		character->use(item);
		return true;
	}

#include <iostream>
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
			cout << ">";
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
	}
	return 0;
}
	
void init_map(Environment * & start, vector<Environment*> & map){
	House * a = new House("hus1",0);
	House * b = new House("hus2",1);
	House * c = new House("hus3",2);
	House * d = new House("hus4",3);
	a->set_neighbour("east", b);
	a->set_neighbour("north", c);
	b->set_neighbour("west", a);
	b->set_neighbour("north", d);
	c->set_neighbour("east", d);
	c->set_neighbour("south", a);
	d->set_neighbour("west", c);
	d->set_neighbour("south", b);

	map.push_back(a);
	map.push_back(b);
	map.push_back(c);
	map.push_back(d);
	start = a;
}


	void init_game(Parser parser,vector<Character*> & npc,Environment * & start,vector<Environment*> & map){
		init_map(start,map);
		init_player(npc, parser, start);
		init_chars(npc,start,map);
		init_objects(map);
		return;
	}

	void init_objects(vector<Environment*> & map){
		Object * sword = new Object("Sword", 0, "A fine sword", 5);
		Object * shield = new Object("Shield", 1, "A fine shield", 6);
		map[1]->drop(sword);
		map[3]->drop(shield);
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
		random_insert(*trolle,map);
		random_insert(*trolla,map);
		npc.push_back(trolle);
		npc.push_back(trolla);
	}

	void gen_npc_actions(vector<Character*> & npcs, Parser parser){
		vector<string> allowed_actions = {"say","move","talk","fight"};
		vector<string> tokens;
		int action;
		for(Character * npc : npcs){
			if(npc->is_player())
				continue;
			action = rand() % allowed_actions.size();
			tokens.push_back(allowed_actions[action]);
			parser.parse_cmd(npc,tokens);
			tokens.clear();
		}
	}

	void split_line(vector<string> & tokens,string cmd){
			istringstream iss(cmd);
			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); //Splittar strängen på whitespace
	}

	void init_player(vector<Character*> & npc, Parser & parser, Environment * & start){
		/*cout << "Choose class: " << endl;
		for(int i = 0; i < parser.num_races(); i++){
			cout << "(" << i+1 << ") : " << parser.races[i] << endl;
		}
		cout << ">";
		
		string inLine;
		getline(cin,inLine);
		int race = atoi(inLine.c_str());
		
if(race  == 0 || !parser.legal_race(race)){
			cout << "Illegal input" << endl;
			init_player(npc,parser,start);
			return;
		}
		*/	
		cout << "Choose name" << endl << ">";
		string name;
		getline(cin,name);
		/*switch(race){
			case 1:
			{*/
				Player * player = new Player(name, 100, start, true);
				npc.push_back(player);
				start->enter(*player);
			/*	break;
			}
			case 2:
			{
				Troll * player = new Troll(name, 100, start, true);
				npc.push_back(player);
				start->enter(*player);
				break;
			}
			default:
				cout << "Someting is horribly wrong. Hide you children, hide your wives cause they are raping everyone up in here!" << endl;
				init_player(npc, parser, start);
				return;
		}*/
		cout << endl;
		return;
	}

	bool  global_speak(Character * character, string line){
		cout << "NPC I SPEAK" << endl;
		if(line == "")
			character->speak();
		else
			character->speak(line);
		return false;
	}
	
	bool global_talk_to(Character * character, string npc){
		cout << "NPC I TALK TO" << endl;
		vector<string> tokens;
		split_line(tokens,npc);
		character->talk_to(tokens);
		return false;
	}
	bool global_move(Character * character, string direction){
		if(!character->is_player())
			cout << "NPC I MOVE" << endl;
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
		cout << "NPC I FIGHT" << endl;
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

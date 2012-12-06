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
	


int main(){
	srand(time(NULL));
	vector<game::Environment*> map;
	vector<game::Character*> npc;
	game::Parser parser;

	game::Environment * start;
	init_game(parser,npc,start,map);
	parser.init_cmds1(parser.cmds);
	parser.init_cmds2(parser.cmds);
	parser.intro();
	bool finished = false;
		vector<string> tokens;
		string command = "";
		game::Character * player = npc.front();
		while(!finished){
			bool pf = false;
			while(!pf){
				tokens.clear();
				cout << ">";
				getline(cin,command);
				split_line(tokens, command);
				parser.parse_cmd(player,tokens);
				/*if(!parser.check_legal(cmd)){
					continue;
				}
				if((unsigned)cmd == parser.cmds.size()-2){
					cout << "byebye" << endl;
					return 1;
				}
				//Här utför player sin action
				if(tokens.size() > 0){
					pf = player->action(cmd, tokens[0]);
				} else {
					pf = player->action(cmd);
				}*/
			}
			//Här utför npc:erna sina moves
			gen_npc_actions(npc,parser);
			cout << endl;
		}
		return 0;
	}
	
	void init_map(game::Environment * & start, vector<game::Environment*> & map){
		game::House * a = new game::House("hus1",0);
		game::House * b = new game::House("hus2",1);
		game::House * c = new game::House("hus3",2);
		game::House * d = new game::House("hus4",3);
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


	void init_game(game::Parser parser,vector<game::Character*> & npc,game::Environment * & start,vector<game::Environment*> & map){
		init_map(start,map);
		init_player(npc, parser, start);
		init_chars(npc,start,map);
		init_objects(map);
		return;
	}

	void init_objects(vector<game::Environment*> & map){
		game::Object * sword = new game::Object("Sword", 0, "A fine sword", 5);
		game::Object * shield = new game::Object("Shield", 1, "A fine shield", 6);
		map[1]->drop(sword);
		map[3]->drop(shield);
	}

	void random_insert(game::Character & ch, vector<game::Environment*>& map){
		int room = rand() % map.size();
		ch.get_pos()->leave(ch);
		ch.set_pos(map[room]);
		map[room]->enter(ch);
	}

	void init_chars(vector<game::Character*> & npc, game::Environment * start,vector<game::Environment*> & map){
		game::Character * trolle = new game::Troll("Trolle", start);
		game::Character * trolla = new game::Troll("Trolla", start);
		random_insert(*trolle,map);
		random_insert(*trolla,map);
		npc.push_back(trolle);
		npc.push_back(trolla);
	}

	void gen_npc_actions(vector<game::Character*> & npc, game::Parser parser){
		unsigned int action;
		unsigned int target;
		unsigned int two_args = false;
		for(unsigned int i = 1; i < npc.size(); i++){
			action = rand() % (parser.cmds.size()-2);
			two_args = rand() % 2;
			if(two_args){
				if(action == 0){ //börja om
					i--;
					continue;
				}
				
				vector<game::Character*> targets = npc[i]->get_pos()->characters;
				target = rand() % targets.size();
				npc[i]->action(action,targets[target]->name());
				continue;
			}
			npc[i]->action(action);
			continue;
		}
	}

	void split_line(vector<string> & tokens,string cmd){
			istringstream iss(cmd);
			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); //Splittar strängen på whitespace
	}

	void init_player(vector<game::Character*> & npc, game::Parser & parser, game::Environment * & start){
		cout << "Choose class: " << endl;
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
			
		cout << "Choose name" << endl << ">";
		string name;
		getline(cin,name);
		switch(race){
			case 1:
			{
				game::Boxer * player = new game::Boxer(name, 100, start, true);
				npc.push_back(player);
				start->enter(*player);
				break;
			}
			case 2:
			{
				game::Troll * player = new game::Troll(name, 100, start, true);
				npc.push_back(player);
				start->enter(*player);
				break;
			}
			default:
				cout << "Someting is horribly wrong. Hide you children, hide your wives cause they are raping everyone up in here!" << endl;
				init_player(npc, parser, start);
				return;
		}
		cout << endl;
		return;
	}
	/*
	bool check_legal(bool & finished, int cmd, game::Parser parser){	
		if(cmd == -1){
			cout << "bad command" << endl;
			parser.help();
			return false;
		}else if(cmd == HELP){
			parser.help();
			return false;
		}
		return true;
	}*/
	void  global_speak(game::Character * character, string line){
		character->speak(line);
	}
	
	void global_talk_to(Character * character, string npc){
		character->talk_to(npc);
	}
	void global_move(Character * character, string direction){
		character->go(direction);
	}
	void global_pick_up(Character * character, string item){
		character->pick_up(item);
	}
	void global_look(Character * character, string a){
		character->look();
	}
	void global_fight(Character * character, string target){
		character->fight(target);
	}

	 

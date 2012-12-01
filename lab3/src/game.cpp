#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "game.h"

#define EXIT 6
#define HELP 7

using namespace std;
	

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
	
	void random_insert(game::Character & ch, vector<game::Environment*>& map){
		int room = rand() % map.size();
		ch.get_pos()->leave(ch);
		ch.set_pos(map[room]);
		map[room]->enter(ch);
	}

	void init_chars(vector<game::Character*> & npc, game::Environment * & start,vector<game::Environment*> & map){
		game::Character * troll1 = new game::Troll("Trolle", start);
		game::Character * troll2 = new game::Troll("Trolla", start);
		random_insert(*troll1,map);
		random_insert(*troll2,map);
		npc.push_back(troll1);
		npc.push_back(troll2);
	}

	void init_game(game::Parser parser, vector<game::Character*> & npc, game::Environment * & start, vector<game::Environment*> & map){
		init_map(start,map);
		init_player(npc, parser, start);
		init_chars(npc,start,map);
		return;
	}

	void gen_npc_actions(vector<game::Character*> & npc, game::Parser parser){
			int action;
			for(unsigned int i = 0; i < npc.size(); i++){
				action = rand() % (parser.cmds.size()-2);
				npc[i]->action(5);
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

			default:
				cout << "Someting is horribly wrong. Hide you children, hide your wives cause they are raping everyone up in here!" << endl;
				init_player(npc, parser, start);
				return;
		}
		cout << endl;
		return;
	}
	
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
	}

	int main(){
		srand(time(NULL));
		vector<game::Environment*> map;
		vector<game::Character*> npc;
		game::Parser parser;

		game::Environment * start;
		init_game(parser,npc,start,map);
		cout << "-------------------------" << endl;
		cout << "\tGAME ON" << endl;
		cout << "-------------------------" << endl;
		bool finished = false;
		vector<string> tokens;
		string command = "";
		game::Character * player = npc.front();
		npc.erase(npc.begin());
		
		while(!finished){
			bool pf = false;
			while(!pf){
				tokens.clear();
				cout << ">";
				getline(cin,command);
				split_line(tokens, command);
				int cmd = parser.parse_cmd(tokens);
				if(!check_legal(finished,cmd,parser)){
					continue;
				}
				if(cmd == EXIT){
					cout << "byebye" << endl;
					return 1;
				}
				//Här utför player sin action
				if(tokens.size() > 0){
					pf = player->action(cmd, tokens[0]);
				} else {
					pf = player->action(cmd);
				}
			}
			//Här utför npc:erna sina moves
			gen_npc_actions(npc,parser);
			cout << endl;
		}
		return 0;
	}
	


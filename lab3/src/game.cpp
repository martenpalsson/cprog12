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
	

	void init_map(game::Environment & start, vector<game::Environment*> & map){
		game::House * b = new game::House("hus2",1);
		game::House * c = new game::House("hus3",2);
		game::House * d = new game::House("hus4",3);
		start.set_neighbour("east", b);
		start.set_neighbour("north", c);
		b->set_neighbour("west", &start);
		b->set_neighbour("north", d);
		c->set_neighbour("east", d);
		c->set_neighbour("south", &start);
		d->set_neighbour("west", c);
		d->set_neighbour("south", b);

		map.push_back(&start);
		map.push_back(b);
		map.push_back(c);
		map.push_back(d);
	}
	
	void random_insert(game::Character & ch, vector<game::Environment*> map){
		int room = rand() % map.size();
		ch.curr_pos->leave(ch);
		ch.curr_pos = map[room];
		map[room]->enter(&ch);
	}

	void init_chars(vector<game::Character*> & characters, game::Environment & start,vector<game::Environment*> & map){
		game::Character * troll1 = new game::Troll("Trolle", &start);
		game::Character * troll2 = new game::Troll("Trolla", &start);
		random_insert(*troll1,map);
		random_insert(*troll2,map);
		characters.push_back(troll1);
		characters.push_back(troll2);
	}

	void init_game(game::Parser parser, vector<game::Character*> & characters, game::Environment & start, vector<game::Environment*> & map){
		init_map(start,map);
		init_player(characters, parser, start);
		init_chars(characters,start,map);
		return;
	}

	void gen_npc_actions(vector<game::Character*> npc, game::Parser parser){
			int action;
			for(unsigned int i = 1; i < npc.size(); i++){
				action = rand() % (parser.cmds.size()-2);
				cout << npc[i]->name();
				cout << " är i " << npc[i]->curr_pos->description() << endl;
				npc[i]->action(5);
			}
	}

	void split_line(vector<string> & tokens,string cmd){
			istringstream iss(cmd);
			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); //Splittar strängen på whitespace
	}

	void init_player(vector<game::Character*> & characters, game::Parser & parser, game::Environment & start){
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
			init_player(characters,parser,start);
			return;
		}
			
		cout << "Choose name" << endl << ">";
		string name;
		getline(cin,name);
		switch(race){
			case 1:
			{
				game::Boxer * player = new game::Boxer(name, 100, &start, true);
				characters.push_back(player);
				start.enter(player);
				break;
			}

			default:
				cout << "Someting is horribly wrong. Hide you children, hide your wives cause they are raping everyone up in here!" << endl;
				init_player(characters, parser, start);
				return;
		}
		cout << endl;
		return;
	}


	int main(){
		srand(time(NULL));
		vector<game::Environment*> map;
		vector<game::Character*> characters;
		game::Parser parser;

		game::House a("hus1",0);
		game::Environment * start = &a;
		
		init_game(parser,characters,*start,map);
		cout << "-------------------------" << endl;
		cout << "\tGAME ON" << endl;
		cout << "-------------------------" << endl;
		bool finished = false;
		vector<string> tokens;
		string command = "";
		game::Character * player = characters.front();

		while(!finished){
			cout << ">"; 
			getline(cin,command); //Läser in ett command
			split_line(tokens, command);
			int cmd = parser.parse_cmd(tokens);
			if(cmd == EXIT){
				finished = true;
				cout << "byebye" << endl;
				return 1;
			}else if(cmd == -1){
				cout << "bad command" << endl;
				parser.help();
			}else if(cmd == HELP){
				parser.help();
			}
			//Här utför player sin action
			if(tokens.size() > 0){
				player->action(cmd, tokens[0]);
			} else {
				player->action(cmd);
			}
			//Här utför npc:erna sina movez
			gen_npc_actions(characters,parser);
			tokens.clear();
			cout << endl;
		}
		return 0;
	}
	


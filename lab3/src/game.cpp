#include "character.h"
#include "environment.h"
#include "object.h"
#include "parser.h"
#include "house.h"
#include "boxer.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sstream>
#include <iterator>
#include <algorithm>

#define EXIT 0

using namespace std;
	

	void init_map(game::Environment * start){
		game::House b("hus2",1);
		game::House c("hus3", 2);
		game::House d("hus4",3);
		start->set_neighbour("east", &b);
		start->set_neighbour("north", &c);
		b.set_neighbour("west", start);
		b.set_neighbour("north", &d);
		c.set_neighbour("east", &d);
		c.set_neighbour("south", start);
		d.set_neighbour("west", &c);
		d.set_neighbour("south", &b);
	}

	void init_chars(vector<game::Character*> & characters, game::Environment * start){
	}

	void init_game(vector<game::Character*> & characters, game::Environment *start){
		init_map(start);
		init_chars(characters,start);
		return;
	}

	int main(){
		vector<game::Character*> characters;
		
		game::House a("hus1",0);
		game::Environment * start = &a;
		
		game::Boxer simost("Busen",103,start);
		start->enter(simost);
		characters.push_back(&simost);
		init_game(characters,start);
		cout << "Chars: " << characters.size() << endl;
		cout << "Start: " << start->description() << endl;
		
		bool finished = false;
		vector<string> tokens;
		string command = "";
		game::Parser parser;
		while(!finished){
			cout << ">"; 
			getline(cin, command); //Läser in ett command
			istringstream iss(command);
			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); //Splittar strängen på whitespace
			int cmd = parser.parse_cmd(tokens);
			if(cmd == EXIT){
				finished = true;
				cout << "byebye" << endl;
				return 1;
			}
			if(cmd == -1){
				cout << "bad command" << endl;
				parser.help();
			}
			//Här ska man utföra sin action!
			
			int action;
			//Här utför npc:erna sina movez
			srand(time(NULL));
			for(unsigned int i = 0; i < 10; i++){
				action = rand() % parser.cmds.size();
			}
			tokens.clear();
		}
		return 0;
	}
	


#include "character.h"
#include "environment.h"
#include "object.h"
#include "parser.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sstream>
#include <iterator>
#include <algorithm>

#define EXIT 0

using namespace std;
	

	/*
	Tänkte att vi kunde sätta ihop lite chars och nån bana här 
	så man kan lira sen. 
	*/
	void init_game(vector<game::Character*> chars){
		//typ Character maestro = wizard("özt,1");
		//chars.push_back(maestro);
		return;
	}

	int main(){
		bool finished = false;
		vector<game::Character*> chars; //Här är alla aktörer
		vector<string> tokens;
		string command = "";
		game::Parser parser;
		init_game(chars);
		while(!finished){
			cout << ">"; 
			getline(cin, command); //Läser in ett command
			istringstream iss(command);
			copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens)); //Splittar strängen på whitespace
			int cmd = parser.parse_cmd(tokens);
			if(cmd == EXIT){
				finished = true;
				cout << "byebye" << endl;
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
	


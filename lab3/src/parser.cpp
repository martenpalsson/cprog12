#include "parser.h"
#include <vector>
#include <string>
#include <iostream>

namespace game {
	
	//Alla commands
	vector<string> Parser::cmds = {"move", "dig", "look", "fight", "talk", "speak", "exit","help"};
	
	vector<string> Parser::races = {"Boxer", "Troll"};

	vector<string> Parser::words = {"to", "at", "with"};

	bool Parser::legal_race(int race){
		return race > 0 && race <= (int) races.size();
	}

	int Parser::num_races(){
		return races.size();
	}

	int Parser::parse_cmd(vector<string> & cmd){
		int command = -1;
		for(unsigned int i = 0; i < cmds.size(); i++){
			if(cmds[i] == cmd[0]){
				command = i;
				cmd.erase(cmd.begin());
				break;
			}
		}
		if(cmd.size() > 0){
			if(isWord(cmd[0])){
				cmd.erase(cmd.begin());
			}
		}
		return command;
	}

	
	bool Parser::isWord(string word){
		for(unsigned int i = 0; i < words.size(); i++){
			if(word == words[i]){
				return true;
			}
		}
		return false;
	}
			
	void Parser::help(){
		cout << endl;
		cout << "Available commands: " << endl;
		for(unsigned int i = 0; i < cmds.size(); i++){
			cout << "\t" << cmds[i] << endl;
		}
		cout << endl;
	}
};

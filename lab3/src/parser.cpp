#include "parser.h"
#include <vector>
#include <string>
#include <iostream>

namespace game {
	
	//Alla commands
	vector<string> Parser::cmds = {"exit", "move", "dig", "look", "fight", "talk to", "speak", "help"};
	
	int Parser::parse_cmd(vector<string> cmd){
		//kollar första ordet
		for(unsigned int i = 0; i < cmds.size(); i++){
			if(cmds[i] == cmd[0]){
				return i;
			}
		}
		return -1;
	}

	void Parser::help(){
		cout << "Commands: " << endl;
		for(unsigned int i = 0; i < cmds.size(); i++){
			cout << cmds[i] << endl;
		}
	}
};

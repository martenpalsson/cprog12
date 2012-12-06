#include "parser.h"
#include "game.h"
#include <vector>
#include <string>
#include <iostream>
#include <functional>

namespace game {
	
	//Alla commands
	map<string, function<void(Character*)>> Parser::cmds1;
	map<string, function<void(Character*, string)>> Parser::cmds2;
	
	vector<string> Parser::races = {"Boxer", "Troll"};

	vector<string> Parser::words = {"to", "at", "with"};

	bool Parser::legal_race(int race){
		return race > 0 && race <= (int) races.size();
	}
	
	void Parser::init_cmds2(map<string, function<void(Character*, string)>> & cmds2){
			cmds2["speak"] = global_speak;
			cmds2["move"] = global_move;
			cmds2["talk to"] = global_talk_to;
			cmds2["pick up"] = global_pick_up;
			cmds2["fight"] = global_fight;
			cmds1["look"] = global_look;
			
			//alias
			cmds2["say"] = global_speak;
			cmds2["mv"] = global_move;
//			cmds["exit"] = exit;
//			cmds["help"] = help;
	}
	void Parser::init_cmds1(map<string, function<void(Character*, string)>> & cmds1){
			cmds1["speak"] = global_speak;
			cmds1["look"] = global_look;
//			cmds["exit"] = exit;
//			cmds["help"] = help;
			
			//alias
			cmds1["say"] = global_speak;
	}

	int Parser::num_races(){
		return races.size();
	}

	void Parser::intro(){
		cout << "-----------------------" << endl;
		cout << "\tFind Trolle" << endl;
		cout << "\tAnd kill him.." << endl;
		cout << "-----------------------" << endl;
	}
	bool Parser::check_legal(int cmd){
		if(cmd == -1){
			cout << "bad command" << endl;
			help();
			return false;
		}else if(cmd == (int)cmds.size()-1){
			help();
			return false;
		}
		return true;
	}

	void Parser::parse_cmd(Character * character, vector<string> & cmd){
		auto it = cmds.find(cmd[0]);
		if(it != cmds.end()){
			if(cmd.size() > 1){
				it->second(character,cmd[1]);
			} else {
				it->second(character, );	
			}
		}
	}/*
		for(unsigned int i = 0; i < cmds.size(); ++i){
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
	*/
	
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
		for(auto it = cmds.begin(); it != cmds.end(); ++it){
			cout << "\t" << it->first << endl;
		}
		cout << endl;
	}
};

#include "parser.h"
#include "game.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <functional>

namespace game {
	
	//Alla commands
	map<string, function<bool(Character*,string)>> Parser::cmds;
	
	vector<string> Parser::races = {"Boxer", "Troll"};

	vector<string> Parser::words = {"to", "at", "with"};

	bool Parser::legal_race(int race){
		return race > 0 && race <= (int) races.size();
	}
	
	void Parser::init_cmds(map<string, function<bool(Character*, string)>> & cmds){
			cmds["speak"] = global_speak;
			cmds["dig"] = global_dig;
			cmds["inventory"] = global_inv;
			cmds["move"] = global_move;
			cmds["talk"] = global_talk_to;
			cmds["pick"] = global_pick_up;
			cmds["fight"] = global_fight;
			cmds["look"] = global_look;
			cmds["status"] = global_status;
			cmds["drop"] = global_drop;
			cmds["use"] = global_use;
			
			//alias
			cmds["equip"] = global_use;
			cmds["attack"] = global_fight;
			cmds["ls"] = global_look;
			cmds["say"] = global_speak;
			cmds["mv"] = global_move;
			cmds["take"] = global_pick_up;
			cmds["inv"] = global_inv;
			cmds["items"] = global_inv;
//			cmds["exit"] = exit;
//			cmds["help"] = help;
	}

	int Parser::num_races(){
		return races.size();
	}

	void Parser::intro(){
		cout << "--------------------------------" << endl;
		cout << "\tFind Trolle" << endl;
		cout << "\tAnd kill him.." << endl;
		cout << "--------------------------------" << endl;
		cout << endl;
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

	bool Parser::parse_cmd(Character * character, vector<string> & cmd){
		auto it = cmds.find(cmd[0]);
		if(it != cmds.end()){
			if(cmd.size() > 1){
				stringstream ss;
				for(unsigned i = 1; i < cmd.size(); ++i){
					ss << cmd[i];
					if(i != cmd.size()-1)
						ss << " ";
				}
				if(character->is_player())
					cout << endl;
				return it->second(character, ss.str());
			} else {
				if(character->is_player())
					cout << endl;
				return it->second(character, "");
			}
		}else{
			cout << "No such command" << endl;
			help();
			return false;
		}
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
		for(auto it = cmds.begin(); it != cmds.end(); ++it){
			cout << "\t" << it->first << endl;
		}
		cout << endl;
	}
};

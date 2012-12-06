#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <functional>
#include "character.h"
#include <iostream>

using namespace std;

namespace game {
	struct Parser {
		static map<string,function<void(Character *,string)>> cmds2;
		static map<string,function<void(Character*)>> cmds1;
		static vector<string> races;
		static vector<string> words;

		void init_cmds2(map<string,function<void(Character*,string)>> & cmds2);
		void init_cmds1(map<string,function<void(Character*)>> & cmds1);
		void parse_cmd(Character * character,vector<string> & command);
		void intro();
		bool check_legal(int cmd);
		int num_races();
		bool legal_race(int race);
		void help();
		bool isWord(string word);
	};
};

#endif

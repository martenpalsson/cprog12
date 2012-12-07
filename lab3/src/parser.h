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
		static map<string,function<bool(Character *,string)>> cmds;
		static vector<string> races;
		static vector<string> words;

		void init_cmds(map<string,function<bool(Character*,string)>> & cmds);
		bool parse_cmd(Character * character,vector<string> & command);
		void intro();
		bool check_legal(int cmd);
		int num_races();
		bool legal_race(int race);
		void help();
		bool isWord(string word);
	};
};

#endif

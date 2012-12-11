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

		void init_cmds(map<string,function<bool(Character*,string)>> & cmds);
		bool parse_cmd(Character * character,vector<string> & command);
		void intro();
		bool check_legal(int cmd);
		void help();
	};
};

#endif

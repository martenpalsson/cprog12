#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "character.h"
#include <iostream>

using namespace std;

namespace game {
	struct Parser {
		static vector<string> cmds;

		int parse_cmd(vector<string> command);
		void help();
	};
};

#endif

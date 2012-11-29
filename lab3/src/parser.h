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
		static vector<string> races;
		static vector<string> words;
		int parse_cmd(vector<string> & command);
		int num_races();
		bool legal_race(int race);
		void help();
		bool isWord(string word);
	};
};

#endif

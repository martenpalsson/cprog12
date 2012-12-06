
#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "environment.h"
#include "object.h"
#include "parser.h"
#include "house.h"
#include "boxer.h"
#include "troll.h" 

#include <string>
#include <vector>

using namespace std;
using namespace game;
void init_map(Environment & start);

void init_chars(vector<Character*> & characters, Environment * start, vector<Environment*> & map);

void init_game(Parser parser, vector<Character*> & characters, Environment * & start, vector<Environment*> & map);

void gen_npc_actions(vector<Character*> & npc, Parser parser);

void split_line(vector<string> & tokens, string cmd);

void init_player(vector<Character*> & characters, Parser & parser, Environment * & start);

void init_objects(vector<Environment*> & map);

void global_speak(Character * c, string line);

void global_talk_to(Character * c, string line);

void global_move(Character * c, string direction);

void global_pick_up(Character * c, string item);

void global_fight(Character * c, string target);

void global_look(Character * c, string a);
#endif


#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "environment.h"
#include "object.h"
#include "hunter.h"
#include "shield.h"
#include "potion.h"
#include "weapon.h"
#include "parser.h"
#include "forest.h"
#include "house.h"
#include "player.h"
#include "troll.h" 

#include <string>
#include <vector>

using namespace std;
using namespace game;
void init_map(Environment & start);

bool read_file();

void init_chars(vector<Character*> & characters, Environment * start, vector<Environment*> & map);

void init_game(Parser parser, vector<Character*> & characters, Environment * & start, vector<Environment*> & map);

void gen_npc_actions(vector<Character*> & npc, Parser parser);

void split_line(vector<string> & tokens, string cmd);

void init_player(vector<Character*> & characters, Parser & parser, Environment * & start);

void init_objects(vector<Environment*> & map);

bool global_speak(Character * c, string line);

bool global_talk_to(Character * c, string line);

bool global_move(Character * c, string direction);

bool global_pick_up(Character * c, string item);

bool global_fight(Character * c, string target);

bool global_look(Character * c, string a);

bool global_inv(Character * c, string a);

bool global_status(Character * c, string a);

bool global_drop(Character * c, string item);

bool global_dig(Character * c, string a);

bool global_use(Character * c, string item);
#endif

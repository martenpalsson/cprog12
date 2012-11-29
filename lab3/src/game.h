
#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "environment.h"
#include "object.h"
#include "parser.h"
#include "house.h"
#include "boxer.h"

#include <string>
#include <vector>

using namespace std;
struct Character;
struct Environment;

void init_map(game::Environment & start);
void init_chars(vector<game::Character*> & characters, game::Environment & start);
void init_game(game::Parser parser, vector<game::Character*> & characters, game::Environment & start);
void gen_npc_actions(vector<game::Character*> npc, game::Parser parser);
void split_line(vector<string> & tokens, string cmd);
void init_player(vector<game::Character*> & characters, game::Parser & parser, game::Environment & start);
int main();
#endif

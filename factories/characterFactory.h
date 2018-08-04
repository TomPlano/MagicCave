#ifndef CHARACTER_FACTORY
#define CHARACTER_FACTORY
#include <random>
#include <fstream>
#include "../products/character.h"
#include "../jsoncpp/dist/json/json.h"
#include <iostream>
#include <cmath>
#include "stdlib.h"
#include <vector>
#include <list>
#include <algorithm>

/*
This class is designed to generate chacters for the map and players to use. A simple bool is used to distinguish players from NPCs.
*/

class CharacterFactory
{
public:
CharacterFactory();
~CharacterFactory();
//This function generates random characters from a json file containg class and race information. The bool tag simply distinguishes which list the object is put in after generation.
Character create_character(bool is_npc);

private:
  int stat_gen();
  std::list<std::string> skill_gen(Json::Value classs);
  std::list<std::string>list_reformat(Json::Value profs);
  std::default_random_engine rng;
  Json::Value race_root;
  Json::Value class_root;

};
#endif

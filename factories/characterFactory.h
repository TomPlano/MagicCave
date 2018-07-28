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


class CharacterFactory
{
public:
CharacterFactory();
~CharacterFactory();
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

#ifndef CHARACTER_FACTORY
#define CHARACTER_FACTORY
#include <random>
#include <fstream>
#include "../products/character.h"
#include "../jsoncpp/dist/json/json.h"
#include <iostream>
#include <cmath>
#include "stdlib.h"


class CharacterFactory
{
public:
CharacterFactory();

Character create_character();

private:
  int stat_gen();
  std::string* skill_gen(Json::Value classs);
  std::default_random_engine rng;
  Json::Value race_root;
  Json::Value class_root;


};
#endif

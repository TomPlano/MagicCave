#ifndef CHARACTER_FACTORY
#define CHARACTER_FACTORY
#include <random>
#include <fstream>
#include "../products/character.h"
#include "../jsoncpp/dist/json/json.h"
#include <iostream>


class CharacterFactory
{
public:
CharacterFactory();

Character create_character();

private:
  std::default_random_engine rng;
  Json::Value class_root;
  Json::Value race_root;


};
#endif

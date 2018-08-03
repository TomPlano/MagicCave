#ifndef MONSTER_FACTORY
#define MONSTER_FACTORY
#include "../products/monsterProduct.h"
#include <random>
#include <fstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "../jsoncpp/dist/json/json.h"

/*
This class is designed to pick random monsters to be encountered throughout the dungeon. The total amount of players along with there average level is taken into account to determine the difficulty of monsters to be encountered.
*/
class MonsterFactory{
public:
  MonsterFactory();
  //Picks a monster from the json list of monster using player level and amount to determine difficulty.
  DungeonMonster create_monster(int player_lvl, int player_count);
private:
  std::default_random_engine rng;
  Json::Value root;


};

#endif

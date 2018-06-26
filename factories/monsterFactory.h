#ifndef MONSTER_FACTORY
#define MONSTER_FACTORY
#include "../products/monsterProduct.h"
#include <random>
#include <fstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "../jsoncpp/dist/json/json.h"

class MonsterFactory{
public:
  MonsterFactory();
  DungeonMonster create_monster(int player_lvl, int player_count);
private:
  std::default_random_engine rng;
  Json::Value root;


};

#endif


#ifndef ITEM_FACTORY
#define ITEM_FACTORY
#include "../products/itemProduct.h"
#include <cstdio>
#include <random>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "../jsoncpp/dist/json/json.h"


class ItemFactory
{
  public:
    ItemFactory();
    ~ItemFactory();
    DungeonItem create_item(int player_lvl, int value);
    std::string IntToString ( int number );
  private:
    std::default_random_engine rng;
    std::discrete_distribution<int> default_dstro {50,30,14,5,1};
    Json::Value root;

};

#endif

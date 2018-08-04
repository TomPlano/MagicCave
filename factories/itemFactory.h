
#ifndef ITEM_FACTORY
#define ITEM_FACTORY
#include "../products/itemProduct.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "../jsoncpp/dist/json/json.h"

/*
This class is designed to pick items from the json file of items. Using player level to determine rarity.
*/
class ItemFactory
{
  public:
    ItemFactory();
    ~ItemFactory();
    //The player level is taken and a discrete distribution is applied to determine the rarity of item that should be found in the cave.
    DungeonItem create_item(int player_lvl, int value);
    std::string IntToString ( int number );

private:
    std::default_random_engine rng;
    std::discrete_distribution<int> default_dstro {50,30,14,5,1};
    Json::Value root;
};

#endif

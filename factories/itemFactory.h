
#ifndef ITEM_FACTORY
#define ITEM_FACTORY
#include "../products/itemProduct.h"
#include "../rapidjson/include/rapidjson/filereadstream.h"
#include "../rapidjson/include/rapidjson/document.h"
#include <cstdio>
#include <random>
class ItemFactory
{
  public:
    ItemFactory();
    ~ItemFactory();
    DungeonItem create_item(int player_lvl, int value);
  private:
    rapidjson::Document itemset;
    std::default_random_engine rng;
    std::discrete_distribution<int> default_dstro {50,30,14,5,1};

};

#endif

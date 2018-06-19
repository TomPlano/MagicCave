
#ifndef ITEM_FACTORY
#define ITEM_FACTORY
#include "../products/itemProduct.h"
#include "../rapidjson/include/rapidjson/filereadstream.h"
#include "../rapidjson/include/rapidjson/document.h"
#include <cstdio>
class ItemFactory
{
  public:
    ItemFactory();
    ~ItemFactory();
    DungeonItem create_item(int player_lvl, int value);
  private:
    rapidjson::Document itemset;
};

#endif

#include "itemFactory.h"


    ItemFactory::ItemFactory(){}
    ItemFactory::~ItemFactory(){}
    DungeonItem ItemFactory::create_item(int player_lvl, int value)
    {
      DungeonItem iprod;
      iprod.set_value(value);
      return iprod;
    }

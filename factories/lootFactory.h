
#ifndef LOOT_FACTORY
#define LOOT_FACTORY
#include "../products/lootProduct.h"
#include "itemFactory.h"
class LootFactory
{
  public:
    LootFactory();
    ~LootFactory();
    DungeonLoot create_loot(int player_lvl);
  private:
    void init();
    ItemFactory ifact;

};

#endif


#ifndef LOOT_FACTORY
#define LOOT_FACTORY
#include "../products/lootProduct.h"
#include "itemFactory.h"

/*
This class is designed to generate packets of loot depending on the level of the players. The algorithm attempts to generate enough loot per dungeon to satisfy one level requirement as stated by the DM's guide.
*/

class LootFactory
{
  public:
    LootFactory();
    ~LootFactory();
    //Takes the player level and generates loot relating to the level
    DungeonLoot create_loot(int player_lvl);
  private:
    void init();
    ItemFactory ifact;

};

#endif

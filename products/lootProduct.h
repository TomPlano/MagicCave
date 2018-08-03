#ifndef LOOT_PRODUCT
#define LOOT_PRODUCT
#include <string>
#include "itemProduct.h"
#include <vector>

/*
This class holds a list of all items that will be found in the map. This way multiple loot drops can be generated and given to either npc's or scattered around the map
*/
class DungeonLoot
{
  public:
    DungeonLoot();
    DungeonItem* get_items();
    void add_item(DungeonItem new_item);
    std::string get_blocktext();
    static int loot_count;
    std::string print_id();
    int PLACEMENT_ID;
    std::vector<DungeonItem> items;

private:
    std::string blocktext;
};

#endif

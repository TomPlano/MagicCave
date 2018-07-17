#ifndef LOOT_PRODUCT
#define LOOT_PRODUCT
#include <string>
#include "itemProduct.h"
#include <vector>


class DungeonLoot
{
  public:
    DungeonLoot();
    std::vector<DungeonItem> get_items();
    void add_item(DungeonItem new_item);
    std::string get_blocktext();
    static int loot_count;
    std::string PLACEMENT_ID;

private:
    std::vector<DungeonItem> items;
    std::string blocktext;
};

#endif

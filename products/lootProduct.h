#ifndef LOOT_PRODUCT
#define LOOT_PRODUCT
#include <string>
#include "itemProduct.h"
#include <vector>


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

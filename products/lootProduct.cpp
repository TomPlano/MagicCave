#include "lootProduct.h"

int DungeonLoot::loot_count=0;
DungeonLoot::DungeonLoot(){
  loot_count++;
}


std::vector<DungeonItem> DungeonLoot::get_items()
{
  return items;
}
std::string DungeonLoot::get_blocktext()
{
  return blocktext;
}
void DungeonLoot::add_item(DungeonItem new_item)
{
  items.push_back(new_item);
}

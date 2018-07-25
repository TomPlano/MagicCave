#include "lootProduct.h"

int DungeonLoot::loot_count=0;
DungeonLoot::DungeonLoot(){
  loot_count++;
}


DungeonItem* DungeonLoot::get_items()
{
    DungeonItem* loot = &items[0];
  return loot;
}
std::string DungeonLoot::get_blocktext()
{
  return blocktext;
}
void DungeonLoot::add_item(DungeonItem new_item)
{
  items.push_back(new_item);
}
std::string DungeonLoot::print_id(){
    char id = PLACEMENT_ID;
    return "["+std::string(1,id)+"]\n";

}

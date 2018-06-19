#include "lootFactory.h"
LootFactory::LootFactory()
{


}
LootFactory::~LootFactory()
{

}
DungeonLoot LootFactory::create_loot(int player_lvl)
{
  DungeonLoot lprod;
  lprod.add_item (ifact.create_item());
  return lprod;
}
void LootFactory::init()
{}

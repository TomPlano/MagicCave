#include "lootFactory.h"
LootFactory::LootFactory()
{


}
LootFactory::~LootFactory()
{

}
DungeonLoot LootFactory::create_loot(int player_lvl)
{
  DungeonLoot loot_parcel;
  int total_value; //in gp
  if(player_lvl<=5)
  {
  total_value=400 + player_lvl * 320;
  }
  else if (player_lvl<=10)
  {
    total_value = 400 + (player_lvl-4)*1600;
  }
  else if (player_lvl<=15)
  {
    total_value = 2000 +(player_lvl-9)*8000;
  }
  else
  {
    total_value = 10000+(player_lvl-14)*40000;
  }

  int v= total_value/10;
  for(int i=0; i<10;i++)
  {
    loot_parcel.add_item (ifact.create_item(player_lvl,v));
  }
  return loot_parcel;
}
void LootFactory::init()
{}

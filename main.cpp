
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include "factories/mapFactory.h"
#include "factories/trapFactory.h"
#include "factories/lootFactory.h"
#include "factories/monsterFactory.h"

#include "products/mapProduct.h"
#include "products/lootProduct.h"
#include "products/monsterProduct.h"



int main (int argc, char* argv[])
{
  if(argc!=4)
  {
    printf("useage: Gen.app <xsize> <ysize> <player lvl>\n");
    return 1;
  }

  int player_lvl=atoi(argv[3]);


//map
  MapFactory mfact (atoi(argv[1]),atoi(argv[2]));
  DungeonMap thingy = mfact.create_map();
  thingy.print_map();

//trap
  TrapFactory tfact;
  DungeonTrap stuff = tfact.create_trap();
  stuff.print_trap();
  DungeonTrap stuff2 = tfact.create_trap();
  stuff2.print_trap();


//loot
  LootFactory lfact;
  DungeonLoot loot_parcel = lfact.create_loot(player_lvl);

  for(int i=0; i<10;i++)
  {
    std::cout<< loot_parcel.get_items().at(i).get_name()<<std::endl;
  }

//monsters
  MonsterFactory monfact;
  DungeonMonster monster = monfact.create_monster(1,6);
  DungeonMonster monster2 = monfact.create_monster(15,6);
  DungeonMonster monster3 = monfact.create_monster(30,6);



  return 0;
}

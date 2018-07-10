
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include "factories/mapFactory.h"
#include "factories/trapFactory.h"
#include "factories/lootFactory.h"
#include "factories/monsterFactory.h"
#include "factories/characterFactory.h"

#include "products/mapProduct.h"
#include "products/lootProduct.h"
#include "products/monsterProduct.h"
#include "products/character.h"



int main (int argc, char* argv[])
{
  if(argc!=5)
  {
    printf("useage: Gen.app <xsize> <ysize> <avg player lvl> <player count>\n");
    return 1;
  }
  int xsize=atoi(argv[1]);
  int ysize=atoi(argv[2]);
  int player_lvl=atoi(argv[3]); //cant go past 30, not gonna check now too lazy
  int player_count=atoi(argv[4]);

//map
  MapFactory mfact (xsize,ysize);
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
  DungeonMonster monster = monfact.create_monster(player_lvl,player_count);

  std::cout<<"Name:"<<monster.get_name()<<" xp:"<<monster.get_xp()<<std::endl;


//pc
  CharacterFactory charfact;
  Character pcs[player_count];
  for(int i=0; i<player_count-1; i++)
  {
    pcs[i] =charfact.create_character();
  }
//npc


  return 0;
}

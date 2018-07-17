
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
    printf("useage: Gen.app <x_size> <y_size> <avg player lvl> <player count>\n");
    return 1;
  }
  int x_size=atoi(argv[1]);
  int y_size=atoi(argv[2]);
  int player_lvl=atoi(argv[3]); //cant go past 30, not gonna check now too lazy
  int player_count=atoi(argv[4]);


//map
  MapFactory mfact (x_size,y_size);
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
  MonsterFactory monster_factory;
  DungeonMonster monster = monster_factory.create_monster(player_lvl,player_count);

  std::cout<<"Name:"<<monster.get_name()<<" xp:"<<monster.get_xp()<<std::endl;


//pc
  CharacterFactory char_factory;
  Character pcs[player_count];
  for(int i=0; i<player_count; i++)
  {
    pcs[i] =char_factory.create_character(false);
    std::cout<<"Character "<<i+1<<" of "<< player_count<<" {"<<std::endl;
    std::cout<<"Race/Class: "<< pcs[i].char_race<<" "<<pcs[i].char_class<<std::endl;
    std::cout<<"First Skill: "<<pcs[i].skills.front()<<std::endl;
    std::cout<<"}"<<std::endl;

  }
//npc
CharacterFactory npc_factory;
Character npcs[5];
for(int i=0; i<5; i++)
{
  npcs[i] =npc_factory.create_character(true);
  std::cout<<"NPC "<<i+1<<" of 5 {"<<std::endl;
  std::cout<<"Race/Class: "<< npcs[i].char_race<<" "<<npcs[i].char_class<<std::endl;
  std::cout<<"First Skill: "<<npcs[i].PLACEMENT_ID<<std::endl;
  std::cout<<"}"<<std::endl;

}




//placement from sets of stuff
  return 0;
}

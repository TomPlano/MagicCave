
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

#include "factories/mapFactory.h"
#include "factories/trapFactory.h"
#include "factories/lootFactory.h"
#include "factories/monsterFactory.h"
#include "factories/characterFactory.h"
#include "factories/populate.h"

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


    int num_traps=10;
    int num_mons=10;
    int num_npcs=10;
    int num_loot=10;//DO NOT CHANGE



    //map
    MapFactory mfact (x_size,y_size);
    DungeonMap dmap = mfact.create_map();

    //trap

    TrapFactory tfact;
    DungeonTrap traps[num_traps];

    for(int i=0; i<num_traps;i++)
    {
        traps[i]=tfact.create_trap();
    }

    //loot
    LootFactory lfact;
    DungeonLoot loots = lfact.create_loot(player_lvl);

    //monsters
    MonsterFactory monster_factory;
    DungeonMonster monsters[num_mons];

    for(int i=0; i<num_mons; i++)
    {
        monsters[i] = monster_factory.create_monster(player_lvl, player_count);
    }


    //npc
    CharacterFactory npc_factory;
    Character npcs[num_npcs];
    for(int i=0; i<num_npcs; i++)
    {
        npcs[i] =npc_factory.create_character(true);
    }

//pc
    CharacterFactory char_factory;
    Character pcs[player_count];
    for(int i=0; i<player_count; i++) {
      pcs[i] = char_factory.create_character(false);
      std::cout << "Character " << i + 1 << " of " << player_count << " {" << std::endl;
      std::cout << "Race/Class: " << pcs[i].char_race << " " << pcs[i].char_class << std::endl;
      std::cout << "First Skill: " << pcs[i].skills.front() << std::endl;
      std::cout << "}" << std::endl;
    }

//placement from sets of stuf
    populate(&dmap, traps, num_traps, loots.get_items(), num_loot,  monsters, num_mons,  npcs, num_npcs);

   

    std::ofstream adventure_log;
    adventure_log.open("Adventure_log.txt");

    adventure_log << "Map\n"; 
    adventure_log << dmap.print_map();
    adventure_log << "\n";

    adventure_log << "Monsters\n"; 
    for(DungeonMonster monster : monsters){
        adventure_log << monster.print_monster();
    }
    adventure_log << "\n";
    adventure_log << "Traps\n"; 
    for(DungeonTrap trap : traps){
        adventure_log << trap.print_trap();
        adventure_log << "\n";
    }
    adventure_log << "\n";
    adventure_log << "Loot\n"; 
    for(DungeonItem item : loots.items){
        std::string item_name = item.print_item();
        adventure_log << item_name;
        adventure_log << "\n";
    }
    adventure_log << "\n";
    
    adventure_log.close();
    return 0;
}



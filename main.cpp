
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

#include <fstream>


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

#include "form/FDFparser.h"
/*
The main function, brings every product and factory together
*/

int main (int argc, char* argv[])
{
  if(argc!=5)
  {
    printf("useage: Gen.app <x_size> <y_size> <avg player lvl> <player count>\n");
    return 1;
  }
  //Gets values from passed args
  int x_size=atoi(argv[1]);
  int y_size=atoi(argv[2]);
  int player_lvl=atoi(argv[3]); //cant go past 30, not gonna check now too lazy
  int player_count=atoi(argv[4]);

    //Sets the amount of things to be generated per map
    int num_traps=10;
    int num_mons=10;
    int num_npcs=10;
    int num_loot=10;//DO NOT CHANGE



    //creates map
    MapFactory mfact (x_size,y_size);
    DungeonMap dmap = mfact.create_map();

    //creates traps
    TrapFactory tfact;
    DungeonTrap traps[num_traps];
    for(int i=0; i<num_traps;i++)
    {
        traps[i]=tfact.create_trap();
    }

    //creates loot
    LootFactory lfact;
    DungeonLoot loots = lfact.create_loot(player_lvl);

    //creates monsters
    MonsterFactory monster_factory;
    DungeonMonster monsters[num_mons];
    for(int i=0; i<num_mons; i++)
    {
        monsters[i] = monster_factory.create_monster(player_lvl, player_count);
    }


    //creates npcs
    CharacterFactory npc_factory;
    Character npcs[num_npcs];
    for(int i=0; i<num_npcs; i++)
    {
        npcs[i] =npc_factory.create_character(true);
    }

    //creates player characters, dependent on amount of players passed as args
    CharacterFactory char_factory;
    Character pcs[player_count];
    for(int i=0; i<player_count; i++) {
      pcs[i] = char_factory.create_character(false);
    }

    //placement of generated objects on the map
    populate(&dmap, traps, num_traps, loots.get_items(), num_loot,  monsters, num_mons,  npcs, num_npcs);

    //Stuff for passsing data to pdf printouts, for printing player characters and NPC data
    FDFparser parser;
    parser.parse_file("pdf/dnd5eCS");
    parser.prep_char_sheets(pcs,player_count);


    //opens the file that will contain the map and legend
    std::ofstream adventure_log;
    adventure_log.open("Adventure_log.txt");

    //Prints the map
    adventure_log << "Map\n";
    adventure_log << dmap.print_map();
    adventure_log << "\n";
    
    //Prints all monsters
    adventure_log << "Monsters\n";
    for(DungeonMonster monster : monsters){
        adventure_log << monster.print_monster();
    }

    //Prints all traps
    adventure_log << "\n";
    adventure_log << "Traps\n";
    for(DungeonTrap trap : traps){
        adventure_log << trap.print_trap();
        adventure_log << "\n";
    }

    //Prints all Loot
    adventure_log << "\n";
    adventure_log << "Loot\n";
    for(DungeonItem item : loots.items){
        std::string item_name = item.print_item();
        adventure_log << item_name;
        adventure_log << "\n";
    }
    adventure_log << "\n";

    //Everything has been generated and printed out for user consumption, enjoy
    adventure_log.close();
    return 0;
}



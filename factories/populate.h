#ifndef POPULATOR
#define POPULATOR
#include "mapFactory.h"
#include "trapFactory.h"
#include "lootFactory.h"
#include "monsterFactory.h"
#include "characterFactory.h"

#include "../products/mapProduct.h"
#include "../products/lootProduct.h"
#include "../products/monsterProduct.h"
#include "../products/character.h"

/*
This class is called after everything has been generated. THe purpose of this class is to fill the map with values to represent objects found in the map. It simply replaces empty tiles '.' with the char id value of different objects. Essentialy making a legend so the make can be read.
*/

int inc_offset(int offset);

template <class T>
//Iterates through each array to populate its information on the map
int place_class(DungeonMap* map, T list ,int count , int id_offset, std::default_random_engine rng, std::uniform_int_distribution<int> xplace, std::uniform_int_distribution<int> yplace );

//is passed all arrays and sends them to the place_class function
int populate(DungeonMap* map, DungeonTrap* traps, int num_traps, DungeonItem* loot, int num_loots, DungeonMonster* monsters, int num_mons, Character* npcs, int num_npcs);


#endif

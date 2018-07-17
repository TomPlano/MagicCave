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



int inc_offset(int offset);

template <class T>
int place_class(DungeonMap* map, T list ,int count , int id_offset, std::default_random_engine rng, std::uniform_int_distribution<int> xplace, std::uniform_int_distribution<int> yplace );

int populate(DungeonMap* map, DungeonTrap* traps, int num_traps, DungeonLoot* loots, int num_loots, DungeonMonster* monsters, int num_mons, Character* npcs, int num_npcs);


#endif

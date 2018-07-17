#include "populate.h"


int inc_offset(int offset){
    offset++;
    if(offset==35||offset==46){
        offset++;
    }
    return offset;
}

template <class T>
int place_class(DungeonMap* map, T list ,int count , int id_offset, std::default_random_engine rng, std::uniform_int_distribution<int> xplace, std::uniform_int_distribution<int> yplace ){
    for(int x = 0; x < count; x ++) {

        list[x].PLACEMENT_ID = id_offset;

         bool invalid = true;
         int xPlace;
         int yPlace;
         while (invalid) {
             xPlace = xplace(rng);
             yPlace = yplace(rng);
             if (map->tiles[xPlace][yPlace].type == 0 and map->tiles[xPlace][yPlace].PLACEMENT_ID == 46) {
                 invalid = false;
                 map->tiles[xPlace][yPlace].PLACEMENT_ID = id_offset;
             }
         }
     id_offset = inc_offset(id_offset);
    }
    return id_offset;
}

int populate(DungeonMap* map, DungeonTrap* traps, int num_traps, DungeonLoot* loots, int num_loots, DungeonMonster* monsters, int num_mons, Character* npcs, int num_npcs)
{
    std::default_random_engine rng;

    std::uniform_int_distribution<int> xplace(0,map->xSize-1);
    std::uniform_int_distribution<int> yplace(0,map->ySize-1);

    int id_offset = 33;
    id_offset = place_class(map, traps,num_traps,id_offset,rng,xplace,yplace);
    id_offset = place_class(map, loots,num_loots,id_offset,rng,xplace,yplace);
    id_offset = place_class(map, monsters,num_mons,id_offset,rng,xplace,yplace);
    id_offset = place_class(map, npcs,num_npcs,id_offset,rng,xplace,yplace);

    return 0;
}



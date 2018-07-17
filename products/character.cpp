#include "character.h"
int Character::npc_count=0;

Character::Character(){}
Character::Character(bool is_npc)
{
    if(is_npc) {
        npc_count++;
        PLACEMENT_ID = "NPC "+ std::to_string(npc_count);
    }
}

Character::~Character(){}

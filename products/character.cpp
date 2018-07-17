#include "character.h"
int Character::npc_count=0;

Character::Character(){}
Character::Character(bool is_npc)
{
    if(is_npc) {
        npc_count++;
    }
}

Character::~Character(){}

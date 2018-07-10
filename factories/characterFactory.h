#ifndef CHARACTER_FACTORY
#define CHARACTER_FACTORY
#include "../products/character.h"
#include "../jsoncpp/dist/json/json.h"


class CharacterFactory
{
public:
CharacterFactory();

Character create_character();

};
#endif

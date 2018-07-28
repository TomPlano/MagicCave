#ifndef CHARACTER_PRODUCT
#define CHARACTER_PRODUCT
#include <string>
#include <list>

class Character
{
public:
    Character();
    Character(bool is_npc);

~Character();
static int npc_count;
std::string char_race;
std::string char_class;
int level;
int str;
int dex;
int con;
int intel;
int wis;
int cha;
int str_mod;
int dex_mod;
int con_mod;
int intel_mod;
int wis_mod;
int cha_mod;
int prof_bonus;
int hp;
int PLACEMENT_ID;
std::string gold;

std::string hit_die;
std::list<std::string> skills;
std::list<std::string> proficiency;
std::list<std::string> armor_profs;
std::list<std::string> weapon_profs;



};
#endif

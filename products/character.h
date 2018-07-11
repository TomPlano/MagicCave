#ifndef CHARACTER_PRODUCT
#define CHARACTER_PRODUCT
#include <string>
#include <list>

class Character
{
public:
Character();
~Character();
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
std::string hit_die;
std::list<std::string> skills;


};
#endif

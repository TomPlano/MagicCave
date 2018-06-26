#include "monsterProduct.h"

DungeonMonster::DungeonMonster(int _challenge,
                int _xp,
                std::string _alignment,
                std::string _type,
                std::string _page,
                std::string _name,
                std::string _size)
{
challenge=_challenge;
xp=_xp;
alignment=_alignment;
type=_type;
page=_page;
name=_name;
size=_size;
}
int DungeonMonster::get_challenge(){return challenge;}
void DungeonMonster::set_challenge(int i){challenge=i;}
int DungeonMonster::get_xp(){return xp;}
void DungeonMonster::set_xp(int i){xp=i;}
std::string DungeonMonster::get_name(){return name;}
void DungeonMonster::set_name(std::string s){name=s;}
std::string DungeonMonster::get_alignment(){return alignment;}
void DungeonMonster::set_alignment(std::string s){alignment=s;}
std::string DungeonMonster::get_type(){return type;}
void DungeonMonster::set_type(std::string s){type=s;}
std::string DungeonMonster::get_page(){return page;}
void DungeonMonster::set_page(std::string s){page=s;}
std::string DungeonMonster::get_size(){return size;}
void DungeonMonster::set_size(std::string s){size=s;}

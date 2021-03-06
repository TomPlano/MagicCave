#include "itemProduct.h"

DungeonItem::DungeonItem(std::string _attunement,
                          std::string _type,
                          std::string _page,
                          std::string _name,
                          std::string _rarity)
{
  attunement = _attunement;
  type = _type;
  page = _page;
  name = _name;
  rarity = _rarity;

}


std::string DungeonItem::get_blocktext(){return blocktext;}
void DungeonItem::set_blocktext(std::string btext){blocktext=btext;}
int DungeonItem::get_value(){return value;}
void DungeonItem::set_value(int _value){value=_value;}

std::string DungeonItem::get_attunement(){return attunement;}
void DungeonItem::set_attunement(std::string s){attunement=s;}
std::string DungeonItem::get_type(){return type;}
void DungeonItem::set_type(std::string s){type=s;}
std::string DungeonItem::get_page(){return page;}
void DungeonItem::set_page(std::string s){page=s;}
std::string DungeonItem::get_name(){return name;}
void DungeonItem::set_name(std::string s){name=s;}
std::string DungeonItem::get_rarity(){return rarity;}
void DungeonItem::set_rarity(std::string s){rarity=s;}

std::string DungeonItem::print_item(){
    char id = PLACEMENT_ID;
    std::string result = "";
    result += "["+std::string(1,id)+"] Name: "+name+"\n";
    result += "\t\tPage: "+page+", Attunemnet: "+attunement+"\n";
    result += "\t\tType: "+type+", Rarity: "+rarity+"\n";

    return result;
}

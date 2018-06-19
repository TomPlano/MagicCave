#include "itemProduct.h"
std::string DungeonItem::get_blocktext()
{
  return blocktext;
}
void DungeonItem::set_blocktext(std::string btext)
{blocktext=btext;}
int DungeonItem::get_value()
{return value;}
void DungeonItem::set_value(int _value)
{value=_value;}

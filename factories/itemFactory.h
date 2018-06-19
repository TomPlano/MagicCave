#include "../products/itemProduct.h"

#ifndef ITEM_FACTORY
#define ITEM_FACTORY
class ItemFactory
{
  public:
    ItemFactory();
    ~ItemFactory();
    DungeonItem create_item(int player_lvl, int value);
  private:
    void init();

};

#endif

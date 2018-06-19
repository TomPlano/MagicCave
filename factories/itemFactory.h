#include "../products/itemProduct.h"

#ifndef ITEM_FACTORY
#define ITEM_FACTORY
class ItemFactory
{
  public:
    ItemFactory();
    ~ItemFactory();
    DungeonItem create_item();
  private:
    void init();

};

#endif

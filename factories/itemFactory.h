
#ifndef ITEM_FACTORY
#define ITEM_FACTORY
#include "../products/itemProduct.h"
#include "../rapidjson/include/rapidjson/document.h"
#include "../rapidjson/include/rapidjson/writer.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
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

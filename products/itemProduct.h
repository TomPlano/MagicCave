#ifndef ITEM_PRODUCT
#define ITEM_PRODUCT
#include <string>


class DungeonItem
{
  public:
    std::string get_blocktext();

  private:
    std::string blocktext;
};

#endif

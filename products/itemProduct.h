#ifndef ITEM_PRODUCT
#define ITEM_PRODUCT
#include <string>


class DungeonItem
{
  public:
    std::string get_blocktext();
    void set_blocktext(std::string btext);
    int get_value();
    void set_value(int value);
  private:
    int value;
    std::string blocktext;
};

#endif

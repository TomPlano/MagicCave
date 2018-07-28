#ifndef ITEM_PRODUCT
#define ITEM_PRODUCT
#include <string>


class DungeonItem
{
  public:
    DungeonItem(std::string _attunement,
                std::string _type,
                std::string _page,
                std::string _name,
                std::string _rarity);
    std::string get_blocktext();
    void set_blocktext(std::string btext);
    int get_value();
    void set_value(int _value);
    std::string get_attunement();
    void set_attunement(std::string s);
    std::string get_type();
    void set_type(std::string s);
    std::string get_page();
    void set_page(std::string s);
    std::string get_name();
    void set_name(std::string s);
    std::string get_rarity();
    void set_rarity(std::string s);
    int PLACEMENT_ID;
    std::string print_item();
private:
    int value;
    std::string blocktext;
    std::string attunement;
    std::string type;
    std::string page;
    std::string name;
    std::string rarity;
};

#endif

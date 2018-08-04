#ifndef MONSTER_PRODUCT
#define MONSTER_PRODUCT
#include <string>

/*
This class is designed to hold information that represents every monster to be used in the map. 

*/

class DungeonMonster{
  public:
    DungeonMonster(std::string _challenge,
                    std::string xp,
                    std::string _alignment,
                    std::string _type,
                    std::string _page,
                    std::string _name,
                    std::string _size);
    std::string get_challenge();
    void set_challenge(std::string i);
    std::string get_xp();
    void set_xp(std::string i);
    std::string get_name();
    void set_name(std::string s);
    std::string get_alignment();
    void set_alignment(std::string s);
    std::string get_type();
    void set_type(std::string s);
    std::string get_page();
    void set_page(std::string s);
    std::string get_size();
    void set_size(std::string s);
    //This function turns all collected information about the monster and turns it into a printable string for easy viewing.
    std::string print_monster();

    static int monster_count;
    int PLACEMENT_ID;
    DungeonMonster();

private:
    std::string challenge;
    std::string xp;
    std::string name;
    std::string alignment;
    std::string type;
    std::string page;
    std::string size;
};
#endif

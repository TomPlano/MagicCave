#include <string>
#ifndef TILE_PRODUCT
#define TILE_PRODUCT


enum tile_type{
  Wall,
  Floor
};
enum modifiers{
  None,
  Water,
  Sand
};

class Tile
{
  public:
    Tile(bool _type);
    void print_tile();
    static int tile_count;
  private:
    tile_type type;
    modifiers mods;
    std::string PLACEMENT_ID;

};

#endif

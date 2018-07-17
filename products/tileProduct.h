#ifndef TILE_PRODUCT
#define TILE_PRODUCT

#include <string>

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
  private:
    tile_type type;
    modifiers mods;
    std::string item_id;

};

#endif

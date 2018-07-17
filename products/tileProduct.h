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
    tile_type type;
    int PLACEMENT_ID;
  private:
    modifiers mods;

};

#endif

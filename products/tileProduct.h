#include <string>
#ifndef TILE_PRODUCT
#define TILE_PRODUCT

/*
This class is designed to hold information on each tile found in the map. The tile's PLACEMENT_ID represents an ASCII char that will be displayed on the map when printed out.
*/

/*
What the type of tile can be during generation
*/
enum tile_type{
  Wall,
  Floor
};
/*
Whether or not the tile contains water or sand or is just regular dirt
Feature unused
*/
enum modifiers{
  None,
  Water,
  Sand
};

class Tile
{
  public:
    Tile(bool _type);
    std::string print_tile();
    static int tile_count;
    tile_type type;
    int PLACEMENT_ID;
  private:
    modifiers mods;

};

#endif

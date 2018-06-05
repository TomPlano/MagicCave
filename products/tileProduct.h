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
    ~Tile();
    void print_tile();
  private:
    tile_type type;
    modifiers mods;
};

#endif

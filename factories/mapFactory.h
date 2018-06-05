#include "../products/mapProduct.h"

#ifndef MAP_FACTORY
#define MAP_FACTORY

class MapFactory
{
  public:
    MapFactory(int x, int y);
    ~MapFactory();
    TileSet create_map(int itterations);
    void print_map();
  private:
    void init_map();
    void itterate_map(bool extra_rule);
    void alloc_map(int xSize, int ySize);
    int wall_check(int radius,int x, int y);
    void walls_up();

    bool** cellFill;
    int xSize, ySize;
};

#endif

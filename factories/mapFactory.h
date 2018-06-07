#include "../products/mapProduct.h"

#ifndef MAP_FACTORY
#define MAP_FACTORY

class MapFactory
{
  public:
    MapFactory(int x, int y);
    ~MapFactory();
    DungeonMap create_map(int itterations);
    void print_map();
  private:
    void init_map();
    void itterate_map(bool extra_rule);
    bool** alloc_map();
    int wall_check(int radius,int x, int y);
    void walls_up();
    void prevent_dc_rooms();
    void clear(bool** grid);
    bool** cellFill;
    bool** buffer;
    int xSize, ySize;
};

#endif

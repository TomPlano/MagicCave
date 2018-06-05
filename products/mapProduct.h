
#ifndef MAP_PRODUCT
#define MAP_PRODUCT
#include "tileProduct.h"

class DungeonMap
{
  public:
    DungeonMap(int _xSize, int _ySize);
    ~DungeonMap();
    void print_map();
    Tile** tiles;
    int xSize, ySize;

};

#endif

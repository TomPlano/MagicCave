
#ifndef MAP_PRODUCT
#define MAP_PRODUCT
#include "tileProduct.h"
#include <string>

class DungeonMap
{
  public:
    DungeonMap(int _xSize, int _ySize);
    ~DungeonMap();
    std::string print_map();
    Tile** tiles;
    int xSize, ySize;

};

#endif

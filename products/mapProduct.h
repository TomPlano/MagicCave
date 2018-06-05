
#ifndef MAP_PRODUCT
#define MAP_PRODUCT
#include "tileProduct.h"

class TileSet
{
  public:
    TileSet(int _xSize, int _ySize);
    ~TileSet();
    Tile** tiles;
    int xSize, ySize;
};

#endif

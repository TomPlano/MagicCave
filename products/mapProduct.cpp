#include "mapProduct.h"
#include <stdlib.h>

TileSet::TileSet(int _xSize, int _ySize)
{
  xSize = _xSize;
  ySize = _ySize;
  tiles = (Tile**)malloc(xSize*sizeof(Tile*));
  for(int i = 0; i < xSize; i++)
  {
      tiles[i] = (Tile*)malloc(ySize*sizeof(Tile));
  }
}
TileSet::~TileSet()
{
  for(int i = 0; i < xSize; i++)
  {
      free(tiles[i]);
  }
}

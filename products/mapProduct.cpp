#include "mapProduct.h"
#include <stdio.h>
#include <stdlib.h>

DungeonMap::DungeonMap(int _xSize, int _ySize)
{
  xSize = _xSize;
  ySize = _ySize;
  tiles = (Tile**)malloc(xSize*sizeof(Tile*));
  for(int i = 0; i < xSize; i++)
  {
      tiles[i] = (Tile*)malloc(ySize*sizeof(Tile));
  }
}
DungeonMap::~DungeonMap() {
    for (int i = 0; i < xSize; i++) {// changex xise to ysize
        free(tiles[i]);
    }
    free(tiles);
}
void DungeonMap::print_map()
{
  for(int i = 0; i < xSize; i++)
  {
    for(int j = 0; j < ySize; j++)
    {
      tiles[i][j].print_tile();
    }
    printf("\n");
  }
}

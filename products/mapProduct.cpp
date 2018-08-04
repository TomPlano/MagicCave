#include "mapProduct.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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
std::string DungeonMap::print_map()
{
    std::string result = "";
    for(int i = 0; i < xSize; i++)
        {
        for(int j = 0; j < ySize; j++)
            {
                result += tiles[i][j].print_tile()+"";
            }
        result += "\n";
  }
    return result;
}

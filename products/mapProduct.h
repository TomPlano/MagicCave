
#ifndef MAP_PRODUCT
#define MAP_PRODUCT
#include "tileProduct.h"
#include <string>

/*
This class holds information on the map. The list of tiles along with the size of the map.
*/
class DungeonMap
{
  public:
    DungeonMap(int _xSize, int _ySize);
    ~DungeonMap();
    //This function turns the map into a printable string
    std::string print_map();
    Tile** tiles;
    int xSize, ySize;

};

#endif

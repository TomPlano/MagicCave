#include "../products/mapProduct.h"

#ifndef MAP_FACTORY
#define MAP_FACTORY

class MapFactory
{
  public:
    MapFactory(int x, int y);
    ~MapFactory();
    TileSet CreateMap(int itterations);
    void print_map();
  private:
    void init_map();
    void itterate_map();
    void allocMap(int xSize, int ySize);
    int** cellFill;
    int xSize, ySize;
};

#endif

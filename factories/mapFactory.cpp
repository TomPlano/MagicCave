#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "mapFactory.h"
#include "../products/mapProduct.h"
#include "../products/tileProduct.h"


//public
MapFactory::MapFactory(int x, int y)
{
  xSize = x;
  ySize = y;
  alloc_map(xSize, ySize);
}
MapFactory::~MapFactory()
{
  for(int i = 0; i < xSize; i++)
  {
      free(cellFill[i]);
  }
  free(cellFill);
}
TileSet MapFactory::create_map(int itterations)
{
  init_map();
  for(int i = 0; i < 4; i++)
  {
    walls_up();
    itterate_map(true);
  }
  for(int i = 0; i < 3; i++)
  {
    walls_up();
    itterate_map(false);

  }


  TileSet tileMap (xSize, ySize); //from mapProduct.h
  for(int i = 0; i < xSize; i++)
  {
    for(int j = 0; j < ySize; j++)
    {
      tileMap.tiles[i][j] = Tile();// Tile(cellFill[i][j])
    }
  }

  return tileMap;
}
void MapFactory::print_map()
{
  for(int i = 0; i < xSize; i++)
  {
    for(int j = 0; j < ySize; j++)
    {
      printf("%i",cellFill[i][j]);
    }
    printf("\n");
  }
}
//private
void MapFactory::init_map()
{
  srand(time(NULL));
  for(int i = 0; i < xSize; i++)
  {
    for(int j = 0; j < ySize; j++)
    {
      if (rand()%2) cellFill[i][j] = 1; //walls are one
      else cellFill[i][j] = 0; //floors are 0
    }
  }

}
void MapFactory::itterate_map(bool extra_rule)
{
  for(int i = 0; i < xSize; i++)
  {
    for(int j = 0; j < ySize; j++)
    {
      if(extra_rule)
      {
        if (wall_check(2,i,j)<=2 || wall_check(1,i,j)>=5) cellFill[i][j] = 1;
        else cellFill[i][j] = 0;
      }
      else
      {
        if (wall_check(1,i,j)>=5) cellFill[i][j] = 1;
        else cellFill[i][j] = 0;
      }
    }
  }
}
void MapFactory::alloc_map(int xSize, int ySize)
{
  cellFill = (bool**)malloc(xSize*sizeof(bool*));
  for(int i = 0; i < xSize; i++)
  {
      cellFill[i] = (bool*)malloc(ySize*sizeof(bool));
  }
}
int MapFactory::wall_check(int radius, int x, int y)
{
  int total = 0;
  for (int i = x-radius; i<= x+radius; i++)
  {
    for (int j= y-radius; j<= y+radius; j++)
    {
      if(i>=0 && i<xSize && j>=0 && j<ySize && cellFill[i][j]) total++;
    }
  }
  //std::cout<<total<<std::endl;
  return total;
}
void MapFactory::walls_up()
{
  for (int i =0; i < xSize; i ++) cellFill[i][0] = 1;
  for (int i =0; i < xSize; i ++) cellFill[i][ySize-1] = 1;
  for (int i =0; i < ySize; i ++) cellFill[0][i] = 1;
  for (int i =0; i < ySize; i ++) cellFill[xSize-1][i] = 1;
}

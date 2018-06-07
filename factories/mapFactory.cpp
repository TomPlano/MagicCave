#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  cellFill = alloc_map();
  buffer = alloc_map();
}
MapFactory::~MapFactory()
{
  for(int i = 0; i < xSize; i++)
  {
      free(cellFill[i]);
  }
  free(cellFill);
}
DungeonMap MapFactory::create_map(int itterations)
{

  init_map();
  for(int i = 0; i < 4; i++)
  {
    itterate_map(true);
  }
  for(int i = 0; i < 3; i++)
  {
    itterate_map(false);

  }

  DungeonMap dungeon_map (xSize, ySize); //from mapProduct.h
  for(int i = 0; i < xSize; i++)
  {
    for(int j = 0; j < ySize; j++)
    {
      dungeon_map.tiles[i][j] = Tile(cellFill[i][j]);
    }
  }

  return dungeon_map;
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
      if (rand()%100>=45) cellFill[i][j] = 1; //walls are one
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
      int wcheck = wall_check(1,i,j);
      if(extra_rule)
      {
        if (wall_check(2,i,j)<=2 || wcheck >=5) buffer[i][j] = 1;
        else buffer[i][j] = 0;
      }
      else
      {
        if (wcheck>=5) buffer[i][j] = 1;
        else buffer[i][j] = 0;
      }
    }
  }
  clear(cellFill);
  bool** temp = cellFill;
  cellFill = buffer;
  buffer = temp;

}
bool** MapFactory::alloc_map()
{
  bool** grid = (bool**)malloc(xSize*sizeof(bool*));
  for(int i = 0; i < xSize; i++)
  {
      grid[i] = (bool*)malloc(ySize*sizeof(bool));
  }
  return grid;
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
  return total;
}
void MapFactory::clear(bool** grid)
{
  for(int i =0; i<xSize; i++)
  memset(grid[i],0,ySize);
}

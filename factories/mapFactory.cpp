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
  allocMap(xSize, ySize);
}
MapFactory::~MapFactory()
{
  for(int i = 0; i < xSize; i++)
  {
      free(cellFill[i]);
  }
  free(cellFill);
}
TileSet MapFactory::CreateMap(int itterations)
{
  init_map();
  for(int i = 0; i < itterations; i++)
  {
    itterate_map();
  }
  //connect rooms etc

  //populate mpa with tiles
  TileSet tileMap (xSize, ySize); //from mapProduct.h
  for(int i = 0; i < xSize; i++)
  {
    for(int j = 0; j < ySize; j++)
    {
      tileMap.tiles[i][j] = Tile();
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
        cellFill[i][j] = rand()%2;
    }
  }

}
void MapFactory::itterate_map()
{
  for(int i = 1; i < xSize-1; i++)
  {
    for(int j = 1; j < ySize-1; j++)
    {
        if(cellFill[i-1][j-1]+cellFill[i-1][j]+cellFill[i-1][j+1]+cellFill[i][j-1]+cellFill[i][j]+cellFill[i][j+1]+cellFill[i+1][j-1]+cellFill[i+1][j]+cellFill[i+1][j+1]>4)
        {
            cellFill[i][j] = 1;
        }
        else
        {
            cellFill[i][j] = 0;
        }
    }
  }
}
void MapFactory::allocMap(int xSize, int ySize)
{
  cellFill = (int**)malloc(xSize*sizeof(int*));
  for(int i = 0; i < xSize; i++)
  {
      cellFill[i] = (int*)malloc(ySize*sizeof(int));
  }
}

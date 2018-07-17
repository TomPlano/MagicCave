#include "tileProduct.h"
#include <stdio.h>
#include <stdlib.h>

int Tile::tile_count=0;

Tile::Tile(bool _type){
  if(_type)type = Wall;
  else type = Floor;
  tile_count++;
  PLACEMENT_ID = "Tile "+ std::to_string(tile_count);

}
void Tile::print_tile(){
  if(type)printf("#");
  else printf(".");
}

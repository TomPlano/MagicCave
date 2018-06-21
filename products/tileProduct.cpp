#include "tileProduct.h"
#include <stdio.h>
#include <stdlib.h>

Tile::Tile(bool _type){
  if(_type)type = Wall;
  else type = Floor;
}
Tile::~Tile(){}
void Tile::print_tile(){
  if(type)printf("#");
  else printf(".");
}

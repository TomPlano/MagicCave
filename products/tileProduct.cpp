#include "tileProduct.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int Tile::tile_count=0;

Tile::Tile(bool _type){
  if(_type){
    PLACEMENT_ID = 46;
    type = Wall;
  } else {
    PLACEMENT_ID = 35;
     type = Floor;
  }
  tile_count++;

}
std::string Tile::print_tile(){
    return std::string(1, PLACEMENT_ID);
}

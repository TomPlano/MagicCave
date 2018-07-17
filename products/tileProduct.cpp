#include "tileProduct.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int Tile::tile_count=0;

Tile::Tile(bool _type){
  if(_type){
    PLACEMENT_ID = ".";
    type = Wall;
  } else {
    PLACEMENT_ID = "#";
     type = Floor;
  }
  tile_count++;

}
void Tile::print_tile(){
    std::cout<<PLACEMENT_ID;
}


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include "factories/mapFactory.h"
#include "factories/trapFactory.h"
#include "products/mapProduct.h"



int main (int argc, char* argv[])
{

  MapFactory mfact (atoi(argv[1]),atoi(argv[2]));
  DungeonMap thingy = mfact.create_map();
  thingy.print_map();
  TrapFactory tfact;

  DungeonTrap stuff = tfact.create_trap();
  stuff.print_trap();
  //not enough time passes here so we need to do something
  DungeonTrap stuff2 = tfact.create_trap();
  stuff2.print_trap();
  return 0;
}
